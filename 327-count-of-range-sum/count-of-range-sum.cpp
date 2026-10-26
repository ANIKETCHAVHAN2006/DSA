class Solution {
    vector<int> tree;
    int size;

    void update(int node, int left, int right, int index) {
        ++tree[node];
        if (left == right) return;

        int mid = left + (right - left) / 2;
        if (index <= mid) {
            update(node * 2, left, mid, index);
        } else {
            update(node * 2 + 1, mid + 1, right, index);
        }
    }

    int query(int node, int left, int right, int ql, int qr) {
        if (qr < left || right < ql) return 0;
        if (ql <= left && right <= qr) return tree[node];

        int mid = left + (right - left) / 2;
        return query(node * 2, left, mid, ql, qr) +
               query(node * 2 + 1, mid + 1, right, ql, qr);
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix{0};
        for (int x : nums) {
            prefix.push_back(prefix.back() + x);
        }

        vector<long long> values;
        for (long long p : prefix) {
            values.push_back(p);
            values.push_back(p - lower);
            values.push_back(p - upper);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        size = values.size();
        tree.assign(4 * size, 0);

        auto indexOf = [&](long long value) {
            return static_cast<int>(
                lower_bound(values.begin(), values.end(), value) - values.begin()
            );
        };

        int answer = 0;
        update(1, 0, size - 1, indexOf(prefix[0]));

        for (int i = 1; i < prefix.size(); ++i) {
            // Count previous prefix sums q where lower <= prefix[i] - q <= upper.
            // Equivalently: prefix[i] - upper <= q <= prefix[i] - lower.
            int left = indexOf(prefix[i] - upper);
            int right = indexOf(prefix[i] - lower);
            answer += query(1, 0, size - 1, left, right);
            update(1, 0, size - 1, indexOf(prefix[i]));
        }

        return answer;
    }
};
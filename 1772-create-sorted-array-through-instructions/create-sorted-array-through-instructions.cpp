class Solution {
    static constexpr int MOD = 1'000'000'007;
    static constexpr int MAX_VALUE = 100'000;

    vector<int> tree;

    void update(int node, int start, int end, int value) {
        if (start == end) {
            ++tree[node];
            return;
        }

        int mid = start + (end - start) / 2;
        if (value <= mid) {
            update(node * 2, start, mid, value);
        } else {
            update(node * 2 + 1, mid + 1, end, value);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];

        int mid = start + (end - start) / 2;
        return query(node * 2, start, mid, left, right) +
               query(node * 2 + 1, mid + 1, end, left, right);
    }

public:
    int createSortedArray(vector<int>& instructions) {
        tree.assign(4 * (MAX_VALUE + 1), 0);

        long long cost = 0;
        for (int x : instructions) {
            int less = query(1, 1, MAX_VALUE, 1, x - 1);
            int greater = query(1, 1, MAX_VALUE, x + 1, MAX_VALUE);

            cost = (cost + min(less, greater)) % MOD;
            update(1, 1, MAX_VALUE, x);
        }

        return static_cast<int>(cost);
    }
};
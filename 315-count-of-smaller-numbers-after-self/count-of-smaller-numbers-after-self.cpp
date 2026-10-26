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

    int query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) return 0;
        if (queryLeft <= left && right <= queryRight) return tree[node];

        int mid = left + (right - left) / 2;
        return query(node * 2, left, mid, queryLeft, queryRight) +
               query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int size = values.size();
        vector<int> tree(4 * max(1, size), 0);
        vector<int> result(nums.size());

        auto updateTree = [&](auto&& self, int node, int left, int right, int index) -> void {
            ++tree[node];
            if (left == right) return;

            int mid = left + (right - left) / 2;
            if (index <= mid) self(self, node * 2, left, mid, index);
            else self(self, node * 2 + 1, mid + 1, right, index);
        };

        auto queryTree = [&](auto&& self, int node, int left, int right,
                             int queryLeft, int queryRight) -> int {
            if (queryRight < left || right < queryLeft) return 0;
            if (queryLeft <= left && right <= queryRight) return tree[node];

            int mid = left + (right - left) / 2;
            return self(self, node * 2, left, mid, queryLeft, queryRight) +
                   self(self, node * 2 + 1, mid + 1, right, queryLeft, queryRight);
        };

        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            int index = lower_bound(values.begin(), values.end(), nums[i]) - values.begin();
            result[i] = (index == 0)
                ? 0
                : queryTree(queryTree, 1, 0, size - 1, 0, index - 1);

            updateTree(updateTree, 1, 0, size - 1, index);
        }

        return result;
    }
};
class NumArray {
    int n;
    vector<int> tree;

    void build(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(node * 2, start, mid, nums);
        build(node * 2 + 1, mid + 1, end, nums);
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
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * max(1, n), 0);
        if (n > 0) build(1, 0, n - 1, nums);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(1, 0, n - 1, left, right);
    }
};
// class NumArray {
//     vector<int> prefix;

// public:
//     NumArray(vector<int>& nums) : prefix(nums.size() + 1, 0) {
//         for (int i = 0; i < nums.size(); ++i) {
//             prefix[i + 1] = prefix[i] + nums[i];
//         }
//     }

//     int sumRange(int left, int right) {
//         return prefix[right + 1] - prefix[left];
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
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

    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        if (index <= mid) {
            updateTree(node * 2, start, mid, index, val);
        } else {
            updateTree(node * 2 + 1, mid + 1, end, index, val);
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
    NumArray(vector<int>& nums) : n(nums.size()), tree(4 * max(1, n), 0) {
        if (n > 0) build(1, 0, n - 1, nums);
    }

    void update(int index, int val) {
        if (n > 0) updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(1, 0, n - 1, left, right);
    }
};

// class NumArray {
//     vector<int> bit;
//     int n;

//     void add(int index, int delta) {
//         for (++index; index <= n; index += index & -index) {
//             bit[index] += delta;
//         }
//     }

//     int prefixSum(int index) {
//         int sum = 0;
//         for (++index; index > 0; index -= index & -index) {
//             sum += bit[index];
//         }
//         return sum;
//     }

// public:
//     NumArray(vector<int>& nums) : n(nums.size()), bit(n + 1, 0) {
//         for (int i = 0; i < n; ++i) {
//             add(i, nums[i]);
//         }
//     }

//     void update(int index, int val) {
//         int current = prefixSum(index) - prefixSum(index - 1);
//         add(index, val - current);
//     }

//     int sumRange(int left, int right) {
//         return prefixSum(right) - prefixSum(left - 1);
//     }
// };
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
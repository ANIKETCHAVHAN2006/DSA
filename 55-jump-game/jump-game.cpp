class Solution {
    vector<int> memo; // -1 = unknown, 0 = false, 1 = true

    bool solve(int i, const vector<int>& nums) {
        if (i >= nums.size() - 1) return true;
        if (memo[i] != -1) return memo[i];

        int furthest = min(
            static_cast<int>(nums.size()) - 1,
            i + nums[i]
        );

        for (int next = i + 1; next <= furthest; ++next) {
            if (solve(next, nums)) {
                return memo[i] = 1;
            }
        }

        memo[i] = 0;
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return solve(0, nums);
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> dp(n, false);
//         dp[n - 1] = true;

//         for (int i = n - 2; i >= 0; --i) {
//             int furthest = min(n - 1, i + nums[i]);

//             for (int next = i + 1; next <= furthest; ++next) {
//                 if (dp[next]) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[0];
//     }
// };
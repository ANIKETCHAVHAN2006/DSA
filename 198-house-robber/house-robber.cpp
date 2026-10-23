class Solution {
    vector<int> memo;

    int solve(int i, const vector<int>& nums) {
        if (i < 0) return 0;
        if (memo[i] != -1) return memo[i];

        int robCurrent = nums[i] + solve(i - 2, nums);
        int skipCurrent = solve(i - 1, nums);

        return memo[i] = max(robCurrent, skipCurrent);
    }

public:
    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return solve(static_cast<int>(nums.size()) - 1, nums);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);

//         for (int i = 1; i <= n; ++i) {
//             int robCurrent = nums[i - 1] + (i >= 2 ? dp[i - 2] : 0);
//             int skipCurrent = dp[i - 1];
//             dp[i] = max(robCurrent, skipCurrent);
//         }

//         return dp[n];
//     }
// };
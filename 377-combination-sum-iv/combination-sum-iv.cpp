class Solution {
    vector<int> memo;

    int solve(int remaining, const vector<int>& nums) {
        if (remaining == 0) return 1;
        if (memo[remaining] != -1) return memo[remaining];

        int ways = 0;
        for (int num : nums) {
            if (num <= remaining) {
                ways += solve(remaining - num, nums);
            }
        }

        return memo[remaining] = ways;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        memo.assign(target + 1, -1);
        return solve(target, nums);
    }
};

// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<unsigned int> dp(target + 1, 0);
//         dp[0] = 1;

//         for (int sum = 1; sum <= target; ++sum) {
//             for (int num : nums) {
//                 if (num <= sum) {
//                     dp[sum] += dp[sum - num];
//                 }
//             }
//         }

//         return static_cast<int>(dp[target]);
//     }
// };
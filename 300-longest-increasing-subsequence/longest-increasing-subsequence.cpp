class Solution {
    vector<vector<int>> memo;

    int solve(int index, int previous, const vector<int>& nums) {
        if (index == nums.size()) return 0;

        int& result = memo[index][previous + 1];
        if (result != -1) return result;

        int best = solve(index + 1, previous, nums); // Skip

        if (previous == -1 || nums[index] > nums[previous]) {
            best = max(best, 1 + solve(index + 1, index, nums)); // Take
        }

        return result = best;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums);
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         vector<int> dp(n, 1);
//         int answer = 1;

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             answer = max(answer, dp[i]);
//         }

//         return answer;
//     }
// };
class Solution {
    int solve(int n, vector<int>& memo) {
        if (n <= 2) return n;

        if (memo[n] != -1) return memo[n];

        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }

  public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};

// class Solution {
//   public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;

//         vector<int> dp(n + 1, 0);
//         dp[1] = 1;
//         dp[2] = 2;

//         for (int step = 3; step <= n; ++step) {
//             dp[step] = dp[step - 1] + dp[step - 2];
//         }

//         return dp[n];
//     }
// };
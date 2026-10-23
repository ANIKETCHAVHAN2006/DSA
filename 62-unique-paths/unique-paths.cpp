class Solution {
    vector<vector<int>> memo;

    int solve(int r, int c, int m, int n) {
        if (r == m - 1 && c == n - 1) return 1;
        if (r >= m || c >= n) return 0;

        int& result = memo[r][c];
        if (result != -1) return result;

        return result = solve(r + 1, c, m, n)
                      + solve(r, c + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return solve(0, 0, m, n);
    }
};

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 1));

//         for (int r = 1; r < m; ++r) {
//             for (int c = 1; c < n; ++c) {
//                 dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };
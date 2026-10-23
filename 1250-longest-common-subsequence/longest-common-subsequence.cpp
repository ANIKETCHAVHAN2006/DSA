class Solution {
    vector<vector<int>> memo;

    int solve(int i, int j, const string& text1, const string& text2) {
        if (i == text1.size() || j == text2.size()) return 0;

        int& result = memo[i][j];
        if (result != -1) return result;

        if (text1[i] == text2[j]) {
            result = 1 + solve(i + 1, j + 1, text1, text2);
        } else {
            result = max(
                solve(i + 1, j, text1, text2),
                solve(i, j + 1, text1, text2)
            );
        }

        return result;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, 0, text1, text2);
    }
};

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size();
//         int n = text2.size();

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for (int i = 1; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (text1[i - 1] == text2[j - 1]) {
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };
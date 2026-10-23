class Solution {
    vector<int> memo;

    int solve(int i, const string& s) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];

        int ways = solve(i + 1, s); // Decode one digit

        if (i + 1 < s.size()) {
            int twoDigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigits <= 26) {
                ways += solve(i + 2, s); // Decode two digits
            }
        }

        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        memo.assign(s.size(), -1);
        return solve(0, s);
    }
};

// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n + 1, 0);
//         dp[n] = 1;

//         for (int i = n - 1; i >= 0; --i) {
//             if (s[i] == '0') continue;

//             dp[i] = dp[i + 1]; // Decode one digit

//             if (i + 1 < n) {
//                 int twoDigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
//                 if (twoDigits <= 26) {
//                     dp[i] += dp[i + 2]; // Decode two digits
//                 }
//             }
//         }

//         return dp[0];
//     }
// };
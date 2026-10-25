// class Solution {
//   public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(),
//              [](const vector<int>& a, const vector<int>& b) {
//                  return a[1] < b[1];
//              });

//         int count = 0;
//         int lastEnd = INT_MIN;

//         for (const auto& p : pairs) {
//             if (p[0] > lastEnd) {
//                 ++count;
//                 lastEnd = p[1];
//             }
//         }

//         return count;
//     }
// };

// class Solution {
//     int solve(int i, vector<vector<int>>& pairs, vector<int>& memo) {
//         if (memo[i] != -1) return memo[i];

//         int best = 1;

//         for (int j = i + 1; j < pairs.size(); ++j) {
//             if (pairs[j][0] > pairs[i][1])
//                 best = max(best, 1 + solve(j, pairs, memo));
//         }

//         return memo[i] = best;
//     }

//   public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end());

//         int n = pairs.size();
//         vector<int> memo(n, -1);
//         int answer = 0;

//         for (int i = 0; i < n; ++i)
//             answer = max(answer, solve(i, pairs, memo));

//         return answer;
//     }
// };

class Solution {
  public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> dp(n, 1);
        int answer = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (pairs[j][0] > pairs[i][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};
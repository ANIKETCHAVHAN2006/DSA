class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();

        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort cut positions
        sort(cuts.begin(), cuts.end());

        int size = m + 2;

        // dp[i][j] = minimum cost to cut between cuts[i] and cuts[j]
        vector<vector<int>> dp(size, vector<int>(size, 0));

        // Length of interval
        for (int len = 2; len < size; len++) {

            for (int i = 0; i + len < size; i++) {

                int j = i + len;

                dp[i][j] = INT_MAX;

                // Try every possible first cut
                for (int k = i + 1; k < j; k++) {

                    int cost = dp[i][k]
                             + dp[k][j]
                             + cuts[j] - cuts[i];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][size - 1];
    }
};
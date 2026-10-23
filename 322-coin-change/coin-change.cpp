class Solution {
    vector<int> memo;

    int solve(int remaining, const vector<int>& coins) {
        if (remaining == 0) return 0;
        if (remaining < 0) return INT_MAX;
        if (memo[remaining] != -1) return memo[remaining];

        int best = INT_MAX;
        for (int coin : coins) {
            int result = solve(remaining - coin, coins);
            if (result != INT_MAX) {
                best = min(best, result + 1);
            }
        }

        return memo[remaining] = best;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -1);
        int answer = solve(amount, coins);
        return answer == INT_MAX ? -1 : answer;
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, amount + 1);
//         dp[0] = 0;

//         for (int value = 1; value <= amount; ++value) {
//             for (int coin : coins) {
//                 if (coin <= value) {
//                     dp[value] = min(dp[value], dp[value - coin] + 1);
//                 }
//             }
//         }

//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };
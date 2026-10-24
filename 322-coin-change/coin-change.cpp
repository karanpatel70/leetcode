class Solution {
public:
    int solve(vector<int>& coins, int amount, int currsum, int i,
              vector<vector<int>>& dp) {

        if (currsum == amount) {
            return 0;
        }

        if (currsum > amount || i >= coins.size()) {
            return INT_MAX;
        }

        if (dp[i][currsum] != -1) {
            return dp[i][currsum];
        }

        // Don't pick the current coin
        int notpick = solve(coins, amount, currsum, i + 1, dp);

        int samepick = INT_MAX;
        int nextpick = INT_MAX;

        if (coins[i] <= amount - currsum) {
            int res1 = solve(coins, amount, currsum + coins[i], i, dp);
            if (res1 != INT_MAX) {
                samepick = 1 + res1;
            }

            int res2 = solve(coins, amount, currsum + coins[i], i + 1, dp);
            if (res2 != INT_MAX) {
                nextpick = 1 + res2;
            }
        }

        return dp[i][currsum] = min({notpick, samepick, nextpick});
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0, 0, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
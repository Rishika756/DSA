class Solution {
public:
    int solve(int i, int tar, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (tar % coins[0] == 0) return tar / coins[0];
            return INT_MAX;
        }
        if (dp[i][tar] != -1) return dp[i][tar];

        int ntake = solve(i - 1, tar, coins, dp);
        int take = INT_MAX;
        if (coins[i] <= tar) {
            int res = solve(i, tar - coins[i], coins, dp);
            if (res != INT_MAX) {
                take = 1 + res;
            }
        }

        return dp[i][tar] = min(ntake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

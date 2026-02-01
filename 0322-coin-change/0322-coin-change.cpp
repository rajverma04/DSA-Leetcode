class Solution {
public:
    vector<vector<int>> dp;
    int minCoins(int ind, vector<int> &coins, int amount) {
        if(ind == 0) {
            if(amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }
        if(dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        int notTake = 0 + minCoins(ind - 1, coins, amount);
        int take = INT_MAX;
        if(coins[ind] <= amount) {
            take = 1 + minCoins(ind, coins, amount - coins[ind]);
        }

        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n + 1, vector<int>(amount + 1, -1));
        int ans = minCoins(n - 1, coins, amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};
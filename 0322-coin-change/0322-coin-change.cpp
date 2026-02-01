class Solution {
public:
    vector<vector<int>> dp;
    int minCoins(int ind, vector<int> &coins, int amount) {
        if(ind == 0) {
            if(amount % coins[0] == 0) {        // if amount is multiple of coin
                return amount / coins[0];
            } else {
                // not possible to form this amount using  given coins
                return 1e9;     
            }
        }
        if(dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        int notTake = 0 + minCoins(ind - 1, coins, amount);
        int take = INT_MAX;
        if(coins[ind] <= amount) {
            // took 1 time(thats why +1) & can again take it that why not subtracting index
            take = 1 + minCoins(ind, coins, amount - coins[ind]);       
        }

        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp.assign(n + 1, vector<int>(amount + 1, -1));
        // int ans = minCoins(n - 1, coins, amount);
        
        // return (ans >= 1e9) ? -1 : ans;

        // Bottom Up
        dp.assign(n + 1, vector<int> (amount + 1, 0));
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) {
                dp[0][t] = t / coins[0];
            } else {
                dp[0][t] = 1e9;
            }
        }

        for(int ind = 1; ind < n; ind++) {
            for(int amt = 0; amt <= amount; amt++) {
                int notTake = 0 + dp[ind - 1][amt];
                int take = INT_MAX;
                if(coins[ind] <= amt) {
                    // took 1 time(thats why +1) & can again take it that why not subtracting index
                    take = 1 + dp[ind][amt - coins[ind]];       
                }
                dp[ind][amt] = min(take, notTake);
            }
        }
        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
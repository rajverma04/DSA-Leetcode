class Solution {
public:
    int find(int index, int buy, int n, vector<int> &prices, vector<vector<int>> &dp) {
        if(index == n) {        // out of array
            return 0;
        }
        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;
        if(buy) {       // 1: buy
            profit = max(-prices[index] + find(index + 1, 0, n, prices, dp),
                            0 + find(index + 1, 1, n, prices, dp)
                        );
        } else {        // 0: sell
            profit = max(prices[index] + find(index + 1, 1, n, prices, dp), 
                            0 + find(index + 1, 0, n, prices, dp)    
                        );
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));     // 2 size as can sell or buy(1: buy, 0: sell)
        
        return find(0, 1, n, prices, dp);
    }
};
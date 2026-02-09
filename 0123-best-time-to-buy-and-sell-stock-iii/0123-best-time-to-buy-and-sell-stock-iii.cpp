class Solution {
public:
    int find(int idx, int n, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if(idx == n || cap == 0) {
            return 0;
        }
        if(dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }

        if(buy) {       // buy
            return dp[idx][buy][cap] = max(-prices[idx] + find(idx + 1, n, 0, cap, prices, dp), 
                                            0 + find(idx + 1, n, 1, cap, prices, dp)
                                            );
        } else {        // sell
            return dp[idx][buy][cap] = max(prices[idx] + find(idx + 1, n, 1,  cap - 1, prices, dp), 
                                            0 + find(idx + 1, n, 0, cap, prices, dp)
                                            );
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return find(0, n, 1, 2, prices, dp);        // cap : 2 transactions allowed
    }
};
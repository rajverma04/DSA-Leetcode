class Solution {
public:
    int find(int idx, int n, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if(idx == n || cap == 0) {
            return 0;
        }
        if(dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }
        
        // jb hum stock lete hai to purse price km hoga isliye minus hai
        if(buy) {       // buy
            return dp[idx][buy][cap] = max(-prices[idx] + find(idx + 1, n, 0, cap, prices, dp),         // buy stock here & cap remains same
                                            0 + find(idx + 1, n, 1, cap, prices, dp)        // not buyed stock here & cap remains same
                                            );
        } else {        // sell
            // jb hum stock profit me sell karte hai to purse price badhega 
            return dp[idx][buy][cap] = max(prices[idx] + find(idx + 1, n, 1,  cap - 1, prices, dp),         // sold stock here & cap reduced as sold
                                            0 + find(idx + 1, n, 0, cap, prices, dp)                    // not sold stock here so cap remains same
                                            );
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));      // 3 cap{2: 2 full buy+sell transactions, 1 : one transaction still can do, 0:  no transaction}

        return find(0, n, 1, 2, prices, dp);        // cap : 2 transactions allowed
    }
};
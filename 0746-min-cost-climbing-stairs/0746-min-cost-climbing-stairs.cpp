class Solution {
public:
    int find(int n, vector<int> &cost, vector<int> &dp) {
        if(n == 0) {
            return cost[0];
        }
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int oneStep = cost[n] + find(n - 1, cost, dp);
        int twoStep = cost[n] + find(n - 2, cost, dp);

        return dp[n] = min(oneStep, twoStep);
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(find(n - 1, cost, dp), find(n - 2, cost, dp));
    }
};
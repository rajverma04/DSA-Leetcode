class Solution {
public:
    int waysPossible(int n, vector<int> &dp) {
        if(n == 0) {        
            return 1;
        }
        if(n < 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        int oneStep = waysPossible(n - 1, dp);     // for 1 step taking at a time
        int twoStep = waysPossible(n - 2, dp);    // for 2 step taking at a time

        return dp[n] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return waysPossible(n, dp);
    }
};
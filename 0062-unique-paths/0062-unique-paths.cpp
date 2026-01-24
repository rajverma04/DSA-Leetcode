class Solution {
public:
    int totalPaths(int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = totalPaths(i - 1, j, dp);
        int left = totalPaths(i, j - 1, dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        // instead of moving top left to bottom right -> moving from bottom right to top left

        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // return totalPaths(m - 1, n - 1, dp);

        // Bottom Up 
        int dp[m][n];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) {
                        up = dp[i - 1][j];      // move up
                    }
                    if(j > 0) {
                        left = dp[i][j - 1];       // move left
                    }
                    dp[i][j] = up + left;
                }
            }
        }

        // return dp[m - 1][n - 1];

        // space optimized
        vector<int> prev(m, 0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) {
                        up = prev[j];      // move up
                    }
                    if(j > 0) {
                        left = curr[j - 1];       // move left
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;

        }

        return prev[n - 1];
    }
};
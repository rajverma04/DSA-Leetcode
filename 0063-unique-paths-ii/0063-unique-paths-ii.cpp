class Solution {
public:
    int r, c;       // r: row, c: col
    vector<vector<int>> dp;
    int countPath(int i, int j, vector<vector<int>>& obsGrid) {
        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) {
            return 0;
        }
        if(obsGrid[i][j] == 1) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up =  countPath(i - 1, j, obsGrid);
        int left = countPath(i, j - 1, obsGrid);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obsGrid) {
        r = obsGrid.size();
        c = obsGrid[0].size();
        if(r == 1 && c == 1 && obsGrid[0][0] != 1) {
            return 1; 
        } 
        if(obsGrid[0][0] == 1 || obsGrid[r-1][c-1] == 1) { 
            return 0; 
        }
        dp.assign(r, vector<int> (c, -1));
        // return countPath(r - 1, c - 1, obsGrid);

        dp.assign(r, vector<int> (c, 0));
        dp[0][0] = 1;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(obsGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if(i > 0) {
                        dp[i][j] += dp[i - 1][j]; 
                    }
                    if(j > 0) {
                        dp[i][j] += dp[i][j - 1]; 
                    }
                }
            }
        }

        return dp[r - 1][c - 1];
    }
};
class Solution {
public:
    int minCost(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) {
            return grid[0][0];
        }
        if(i < 0 || j < 0) {        // out of boundary
            return INT_MAX;         
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = minCost(i - 1, j, grid, dp);
        int left = minCost(i, j - 1, grid, dp);

        int best = min(up, left);
        if(best == INT_MAX) return dp[i][j] = INT_MAX;      // safe from integer overflow 

        return dp[i][j] = grid[i][j] + best;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return minCost(m - 1, n - 1, grid, dp);

    }
};
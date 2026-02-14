class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {0};

        // top glass
        dp[0][0] = poured;
        for(int r = 0; r < query_row; r++) {
            for(int c = 0; c <= r; c++) {
                if(dp[r][c] > 1.0) {        // overflow
                    double excess = dp[r][c] - 1.0;

                    // split equally
                    dp[r + 1][c] += excess / 2.0;
                    dp[r + 1][c + 1] += excess / 2.0;
                }
            }
        }

        // glass cannot exceed 1
        if(dp[query_row][query_glass] > 1.0) {
            return 1.0;
        }

        return dp[query_row][query_glass];
    }
};
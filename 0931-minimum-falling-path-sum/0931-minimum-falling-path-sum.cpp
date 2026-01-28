class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> prev(col, 0), curr(col, 0);

        for(int i = 0; i < col; i++) {      // fill the prev with first row value
            prev[i] = matrix[0][i];
        }

        for(int i = 1; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int up = matrix[i][j] + prev[j];
                int leftDiagonal = matrix[i][j];
                if(j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal += 1e9;
                }

                int rightDiagonal = matrix[i][j];
                if(j  + 1 < col) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal += 1e9;
                }

                curr[j] = min({leftDiagonal, rightDiagonal, up});
            }
            prev = curr;
        }

        int mini = 1e9;

        for(int i = 0; i < col; i++) {
            mini = min(mini, prev[i]);
        }

        return mini;
    }
};
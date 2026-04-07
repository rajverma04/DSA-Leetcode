class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            // same column upward
            for(int k = i; k >= 0; k--) {
                matrix[k][j] = 0;
            }

            // same column downward
            for(int k = i; k < row; k++) {
                matrix[k][j] = 0;
            }

            // same row left
            for(int k = j; k >= 0; k--) {
                matrix[i][k] = 0;
            }

            // same row right
            for(int k = j; k < col; k++) {
                matrix[i][k] = 0;
            }
        }

    }
};
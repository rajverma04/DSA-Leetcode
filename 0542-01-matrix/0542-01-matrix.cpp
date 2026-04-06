class Solution {
public:
    int row, col;
    bool validMove(int i, int j) {
        return (i >= 0 && j >= 0 && i < row && j < col);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if(validMove(ni, nj)) {
                    if(mat[ni][nj] > mat[i][j] + 1) {
                        mat[ni][nj] = mat[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return mat;
    }
};
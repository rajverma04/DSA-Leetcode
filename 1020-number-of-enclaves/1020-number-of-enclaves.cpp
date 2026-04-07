class Solution {
public:
    int row, col;
    bool validMove(int i, int j) {
        return (i >= 0 && i < row && j >= 0 && j < col);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();

        queue<pair<int, int>> q;
        // Pushing only border 1's
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;     // mark visited
                }
            }
        }

        int rd[4] = {-1, 1, 0, 0};
        int cd[4] = {0, 0, -1, 1};

        // mark all the neighbor 1's of queue visited as 0, the left one will become answer
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + rd[k];
                int nj = j + cd[k];

                if (validMove(ni, nj) && grid[ni][nj] == 1) {
                   grid[ni][nj] = 0;
                    q.push({ni, nj});
                }
            }
        }

        int count = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
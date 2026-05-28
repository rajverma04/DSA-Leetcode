class Solution {
public:
    bool validMove(int i, int j, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return (i > -1 && i < row && j > -1 && j < col);
    }
    int BFS(int i, int j, vector<vector<int>>& grid) {
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        
        int perimeters = 0;
        queue<pair<int, int>> q;
        q.push({i, j});

        grid[i][j] = -1;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                if(validMove(ni, nj, grid) && grid[ni][nj] == 1) {
                    grid[ni][nj] = -1;
                    q.push({ni, nj});
                } else if(!validMove(ni, nj, grid) || grid[ni][nj] == 0) {
                    perimeters++;
                }
            }
        }

        return perimeters;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    return BFS(i, j, grid);
                }
            }
        }

        return 0;
    }
};
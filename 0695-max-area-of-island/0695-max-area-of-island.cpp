class Solution {
public:
    int r,c;
    
    bool validMove(int i, int j) {
        return (i > -1 && j > -1 && i < r && j < c);
    }
    
    int BFS(int i, int j, vector<vector<int>>& grid) {
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        int area = 1;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                if (validMove(i + row[k], j + col[k]) &&
                    grid[i + row[k]][j + col[k]] == 1) {
                    area++;
                    grid[i + row[k]][j + col[k]] = 0;     // mark that location 0 as already visited
                    q.push({i + row[k], j + col[k]});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        r = grid.size(), c = grid[0].size();
        int mx = 0;    
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1 ) {
                    int area = BFS(i, j, grid);
                    mx = max(mx, area);
                }
            }
        }

        return mx;
    }
};
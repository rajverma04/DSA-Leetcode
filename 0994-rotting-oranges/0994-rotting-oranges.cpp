class Solution {
public:
    bool check(int i, int j, int row, int col) {        // valid memory access
        return i > -1 && i < row && j > -1 && j < col;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int, int>, int>> q;     // row, col, timer

        int goodOranges = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    goodOranges++;
                } else if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});     // initially 0 timer
                }
            }
        }

        int i,j, timer = 0;
        while(!q.empty()) {
            i = q.front().first.first;
            j = q.front().first.second;
            timer = q.front().second;
            q.pop();

            if(check(i - 1, j, row, col) && grid[i - 1][j] == 1) {       // up
                grid[i - 1][j] = 0;
                goodOranges--;
                q.push({{i - 1, j}, timer + 1});
            }
            if(check(i + 1, j, row, col) && grid[i + 1][j] == 1) {       // down
                grid[i + 1][j] = 0;
                goodOranges--;
                q.push({{i + 1, j}, timer + 1});
            }
            if(check(i, j - 1, row, col) && grid[i][j - 1] == 1) {       // left
                grid[i][j - 1] = 0;
                goodOranges--;
                q.push({{i, j - 1}, timer + 1});
            }
            if(check(i, j + 1, row, col) && grid[i][j + 1] == 1) {       // right
                grid[i][j + 1] = 0;
                goodOranges--;
                q.push({{i, j + 1}, timer + 1});
            }
        }

        if(goodOranges > 0) {
            return -1;
        }

        return timer;
    }
};
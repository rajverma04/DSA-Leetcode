class Solution {
public:
    bool validMove(int i, int j, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return (i > -1 && i < row && j > -1 && j < col);
    }
    int DFS(int i, int j, vector<vector<int>>& grid) {
        if(!validMove(i, j, grid) || grid[i][j] == 0) {
            return 1;
        }
        
        if(grid[i][j] == -1) {
            return 0;
        }

        grid[i][j] = -1;

        int perimeters = 0;
        
        perimeters += DFS(i - 1, j, grid);
        perimeters += DFS(i + 1, j, grid);
        perimeters += DFS(i, j - 1, grid);
        perimeters += DFS(i, j + 1, grid);

        return perimeters;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    return DFS(i, j, grid);
                }
            }
        }

        return 0;
    }
};
class Solution {
public:
    int m, n, initColor;
    bool checkValidMove(int i, int j) {
        return (i > -1 && j > -1 && i < m && j < n);
    }

    void dfs(int i, int j, vector<vector<int>> &temp, int color) {
        int row[4] = {-1, 0, 0, 1};
        int col[4] = {0, -1, 1, 0};

        temp[i][j] = color;

        for(int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];
            if(checkValidMove(ni, nj) && temp[ni][nj] == initColor) {
                dfs(ni, nj, temp, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        initColor = image[sr][sc];
        if(initColor == color) {
            return image;
        }
        
        vector<vector<int>> temp = image;

        dfs(sr, sc, temp, color);
        return temp;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int n = s.size();
        int cycle = 2 * (numRows - 1);

        // Safe column calculation
        int cycles = (n + cycle - 1) / cycle;   // ceil
        int cols = cycles * (numRows - 1);

        vector<vector<char>> grid(numRows, vector<char>(cols, ' '));

        int i = 0; // index for string
        int col = 0;
        while(i < n) {
            // move vertically
            for(int row = 0; row < numRows && i < n; row++) {
                grid[row][col] = s[i++];
            }

            // move diagonally
            for(int row = numRows - 2; row >= 1 && i < n; row--) {
                col++;
                grid[row][col] = s[i++];
            }
            // move to next vertical col
            col++;              
        }

        string ans = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] != ' ') {
                    ans += grid[i][j];
                }
            }
        }

        return ans;
       
    }
};


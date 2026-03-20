class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char dig) {
        // horizontally
        for(int j = 0; j < 9; j++) {        // move in column
            if(board[row][j] == dig) {
                return false;
            }
        }

        // vertically
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }
        // cell of 3x3
        int srow = (row / 3) * 3;       // start row
        int scol = (col / 3) * 3;       // start col

        for(int i = srow; i <= srow + 2; i++) {
            for(int j = scol; j <= scol + 2; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }
    bool helper(int row, int col, vector<vector<char>>& board) {
        if(row == 9) {      // reached to last row and last col
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return helper(nextRow, nextCol, board);
        }

        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(row, col, board, dig)) {
                board[row][col] = dig;
                if(helper(nextRow, nextCol, board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0, 0, board);
    }
};
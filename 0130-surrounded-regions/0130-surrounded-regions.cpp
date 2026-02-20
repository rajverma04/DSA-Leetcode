class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board) {
        int row = board.size();
        int col = board[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';

        dfs(i + 1, j, board);   // next row, same col
        dfs(i - 1, j, board);   // prev row, same col
        dfs(i, j + 1, board);   // same row, next col
        dfs(i, j - 1, board);   // same row, prev col
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // mark boundary cell as that cannot be sournded with X as safe
        for(int i = 0; i < row; i++) {
            dfs(i, 0, board);
            dfs(i, col - 1, board);
        }

        // mark boundary cell as that cannot be sournded with X as safe
        for(int i = 0; i < col; i++) {
            dfs(0, i, board);
            dfs(row - 1, i, board);
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // revert the safe marked cell to original form
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
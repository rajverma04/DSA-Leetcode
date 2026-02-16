class Solution {
public:
    int r, c;
    bool validMove(int i, int j) {
        return (i > -1 && j > -1 && i < r && j < c);
    }
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int idx) {
        if(idx == word.size()) {
            return true;
        }
        if(!validMove(i, j) || board[i][j] != word[idx]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(i + 1, j, board, word, idx + 1) || dfs(i - 1, j, board, word, idx + 1) ||
                    dfs(i, j + 1, board, word, idx + 1) || dfs(i, j - 1, board, word, idx + 1);
        
        board[i][j] = ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(dfs(i, j, board, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
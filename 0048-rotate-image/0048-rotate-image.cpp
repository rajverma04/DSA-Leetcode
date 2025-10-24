class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose first
        int row = matrix.size();
        // int col = matrix[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = i + 1; j < row; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // flip vertically

         for (int i = 0; i < row; i++) {
            for (int j = 0; j < row / 2; j++) {
                swap(matrix[i][j], matrix[i][row - j - 1]);
            }
        }
    }
};
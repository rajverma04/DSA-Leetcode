class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        bool firstRow = false, firstCol = false;

        // Step 1: Check first row
        for(int j = 0; j < col; j++) {
            if(matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Step 2: Check first column
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Step 3: Mark rows & cols
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Fill based on markers
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Handle first row
        if(firstRow) {
            for(int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Handle first column
        if(firstCol) {
            for(int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
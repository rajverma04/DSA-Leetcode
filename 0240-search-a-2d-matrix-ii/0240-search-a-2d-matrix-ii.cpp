class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;

        while(i >= 0 && j < col) {
            if(matrix[i][j] == target) {
                return 1;
            } else if(matrix[i][j] < target) {  // if target > then move to right
                j++;
            } else {       // // if target < then move to upside
                i--;
            }
        }
        return 0;
    }
};
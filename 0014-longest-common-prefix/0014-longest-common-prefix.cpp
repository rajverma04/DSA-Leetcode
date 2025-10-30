class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        int minCol = INT_MAX;
        for(int i = 0; i < strs.size(); i++) {
            if(minCol > strs[i].size()) {   // to get the size of min length of string
                minCol = strs[i].size();
            }
        }
        int count = 0;
        for(int col = 0; col < minCol; col++) {
            char currentChar = strs[0][col];
            for(int row = 1; row < strs.size(); row++) {
                if(strs[row][col] != currentChar) {
                    return strs[0].substr(0, count);    // if early mismatch is found in array
                }
            }
            count++;
        }

        return strs[0].substr(0, count);    // if there is no mismatch
    }
};
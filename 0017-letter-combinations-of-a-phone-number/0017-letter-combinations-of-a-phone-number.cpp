class Solution {
public:
    void fun(string& digits, vector<string>&ans, vector<string>&mapping, string temp, int index) {
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int pos = digits[index] - '2';
        for(int i = 0; i < mapping[pos].size(); i++) {
            fun(digits, ans, mapping, temp + mapping[pos][i], index + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) {
            return ans;
        }

        vector<string> mapping(8);
        mapping[0] = "abc";
        mapping[1] = "def";
        mapping[2] = "ghi";
        mapping[3] = "jkl";
        mapping[4] = "mno";
        mapping[5] = "pqrs";
        mapping[6] = "tuv";
        mapping[7] = "wxyz";
        fun(digits, ans, mapping, "", 0);
        return ans;
    }
};
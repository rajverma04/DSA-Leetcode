class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str = "";
        while(columnNumber > 0) {
            columnNumber--;     // shift for 1–26 system

            int rem = columnNumber % 26; // letter index
            str.push_back('A' + rem);

            columnNumber /= 26;     // reduce number
        }   

        reverse(str.begin(), str.end());

        return str;
    }
};

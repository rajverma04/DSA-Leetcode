class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 65 && s[i] <= 90) || ((s[i] >= 97 && s[i] <= 122)) || ((s[i] >= 48 && s[i] <= 57))) {
                s[i] = tolower(s[i]);
                str += s[i];
            }
        }
        
        int start = 0, end = str.size() - 1;
        while(start < end) {
            if(str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
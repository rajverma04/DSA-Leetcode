class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {      // if both matched move i pointer forward to compare
                i++;
            }

            j++;        // since t size is greater or need to compare from that move pointer always forward
        }

        return i == s.size();
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int length = 0;
        int start = 0;
        if(s.size() == 0) {
            return 0;
        }
        if(s.size() == 1) {
            return 1;
        }
        st.insert(s[0]);
        for(int i = 1; i < s.length(); i++) {
            while(st.find(s[i]) != st.end()) {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[i]);
            length = max(length, (int)st.size());
        }

        return length;
    }
};
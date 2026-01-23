class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        
        while(!s.empty() && s.front() == ' ') {
            s.erase(s.begin());
        }
        while(!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        int n = s.size() - 1;
        string str = "";
        for(int i = n; i >= 0; i--) {
            if(s[i] != ' ') {
                st.push(s[i]);
            } else {
                while(!st.empty()) {
                    str += st.top();
                    st.pop();
                }
                if(str.back() != ' ') {
                    str += ' ';
                }
            }
        }

        while(!st.empty()) {
            str += st.top();
            st.pop();
        }

        return str;
    }
};
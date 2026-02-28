class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {     // opening bracket
                st.push(s[i]);
            } else {                // closing bracket
                if(st.empty()) {        // checking stack is empty or not
                    return 0;
                } else if(s[i] == ')') {        // for ) bracket
                    if(st.top() != '(') {
                        return 0;
                    } else {
                        st.pop();
                    }
                } else if(s[i] == ']') {           // for ] bracket
                    if(st.top() != '[') {
                        return 0;
                    } else {
                        st.pop();
                    }
                } else {
                    if(st.top() != '{') {       // for } bracket
                        return 0;
                    } else {
                        st.pop();
                    }
                }
            }
        }
        return st.empty();      // agar stack empty hai mtlb sara bracket balance ho chuka hai 
    }
};
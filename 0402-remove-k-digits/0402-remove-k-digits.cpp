class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string str;
        char ch;

        for(auto x : num) {
            int digit = x - '0';
            while(st.size() && st.top() > digit && k) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k--) {        // if k exist then pop greater element
            st.pop();
        }

        while(st.size()) {      // adding remaing digit to str
            ch = '0' + st.top();
            st.pop();
            str += ch;
        }

        int i = str.size() - 1;

        while(i >= 0 && str[i] == '0') {        // remove 0 from begining
            str.pop_back();
            i--;
        }

        if(str.size() == 0) {   // if stack is empty
            return "0";
        }
        reverse(str.begin(), str.end());

        return str;

    }
};
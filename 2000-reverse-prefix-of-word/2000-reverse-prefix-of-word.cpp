class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch) {
                idx = i;
                break;

            }
        }
        if(idx == -1) {
            return word;
        }
        // reverse(word.begin(), word.begin() + idx + 1);
        // return word;


        stack<char> st;
        int i = 0;
        while(i != idx) {
            st.push(word[i]);
            i++;
        }
        st.push(word[i]);
        int j = 0;
        while(!st.empty()) {
            word[j++] = st.top();
            st.pop();
        }

        return word;
    }
};
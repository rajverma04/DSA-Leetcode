class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";

        while(str.length() < k){
            int size = str.length();
            for(int i = 0; i < size; i++) {
                char ch = str[i] + 1;
                if (ch > 'z') {
                    ch = 'a';
                } 
                str += ch;
            }
        }

        return str[k - 1];
    }
};
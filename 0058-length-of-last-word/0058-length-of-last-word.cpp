class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;
        while(i >= 0 && s[i] == ' ') {      // remove trailing space
            i--;
        }
        while(i >= 0 && s[i] != ' '){       // count the length of last word till second last space found
            i--;
            length++;
        }

        return length;
    }
};
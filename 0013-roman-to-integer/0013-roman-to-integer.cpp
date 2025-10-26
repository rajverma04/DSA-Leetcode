class Solution {
public:
    int char2num(char a) {
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1])) {
                num -= char2num(s[i]);
            } else {
                num += char2num(s[i]);
            }
        }


        // for(int i = 0; i < s.length(); i++) {
        //     if(i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'V') {
        //         num += 4;
        //         i++; // skip next character
        //         continue;
        //     }
        //     if(i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'X') {
        //         num += 9;
        //         i++;
        //         continue;
        //     }
        //     if(i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'L') {
        //         num += 40;
        //         i++;
        //         continue;
        //     }
        //     if(i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'C') {
        //         num += 90;
        //         i++;
        //         continue;
        //     }
        //     if(i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'D') {
        //         num += 400;
        //         i++;
        //         continue;
        //     }
        //     if(i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'M') {
        //         num += 900;
        //         i++;
        //         continue;
        //     }

        //     if(s[i] == 'I') {
        //         num += 1;
        //     } else if(s[i] == 'V') {
        //         num += 5;
        //     } else if(s[i] == 'X') {
        //         num += 10;
        //     } else if(s[i] == 'L') {
        //         num += 50;
        //     } else if(s[i] == 'C') {
        //         num += 100;
        //     } else if(s[i] == 'D') {
        //         num += 500;
        //     } else if(s[i] == 'M') {
        //         num += 1000;
        //     }
        // }
        return num;
    }
};
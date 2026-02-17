class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h < 12; h++) {           // h->hour
            for(int m = 0; m < 60; m++) {       // m->minute
                // __builtin_popcount : it is a compiler GCC function to count no. of 1s bit in binary number
                // binary of (5: 101) then __builtin_popcount returns 2(as two 1s present)
                int count = __builtin_popcount(h) + __builtin_popcount(m);    

                if(count == turnedOn) {
                    string str = to_string(h) + ":";

                    if(m < 10) {        // if min less than 10 then add 0
                        str += "0";
                    }
                    str += to_string(m);
                    ans.push_back(str);
                }
            }
        }

        return ans;
    }
};
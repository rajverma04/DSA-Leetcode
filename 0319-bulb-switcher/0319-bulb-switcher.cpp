class Solution {
public:
    int count = 0;
    void switchBulbs(vector<bool> &bulb, int round) {
        int i = round - 1;
        while(i < bulb.size()) {
            bulb[i] = !bulb[i];
            i += round;
        }
    }
    int bulbSwitch(int n) {
        // int round = 1;
        vector<bool> bulb(n, false);

        // while(round <= n) {
        //     switchBulbs(bulb, round);
        //     round++;
        // }

        // for(int i = 0; i < n; i++) {
        //     if(bulb[i]) {
        //         count++;
        //     }
        // }

        return sqrt(n);
        // return count;
    }


};
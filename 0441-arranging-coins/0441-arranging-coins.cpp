class Solution {
public:
    int arrangeCoins(int n) {
        int stair = 0;

        int count = 1;
        while(n >= count) {
            stair++;
            n -= count;
            count++;
        }
        return stair;
    }
};
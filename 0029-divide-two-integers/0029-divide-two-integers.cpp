class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) {
            return INT_MAX - 1;
        }
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // long long result = (long long)dividend / (long long)divisor;
        // if(dividend > INT_MAX - 1) {
        //     return INT_MAX;
        // }
        // if(dividend < INT_MAX) {
        //     return INT_MIN;
        // }
        return dividend / divisor;
    }
};
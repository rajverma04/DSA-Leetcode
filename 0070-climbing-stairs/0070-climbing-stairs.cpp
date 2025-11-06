class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;       
        } 

        int a = 1, b = 2;          // f(1), f(2)
        for (int i = 3; i <= n; ++i) {
            int c = a + b;         // f(i) = f(i-1) + f(i-2)
            a = b;
            b = c;
        }
        return b;

        // Using recursion time complexity increases
        // if(n == 1) {
        //     return 1;
        // }
        // if(n == 2) {
        //     return 2;
        // }
        // return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) {
            return false;
        }
        if(n == 1) {
            return true;
        }
        
        // repeatedly removes these allowed factors: 2, 3, 5
        while(n % 2 == 0) {
            n /= 2;
        }
        while(n % 3 == 0) {
            n /= 3;
        }
        while(n % 5 == 0) {
            n /= 5;
        }


        // after removing the factor 2,3,5 number becomes 1
        return n == 1;
        
    }
};
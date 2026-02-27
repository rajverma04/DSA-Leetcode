class Solution {
public:
    int catalan(int n) {
        // catalan base condition: C0 = 1, C1 = 1
        if(n <= 1) {        
            return 1;
        }
        int res = 0;
        for(int i = 0; i <= n - 1; i++) {
            // C(n) = C0C(n-1) + C1C(n-2) +.... + C(n-1)C0
            res += catalan(i) * catalan(n - i - 1);
        }
        return res;

    }
    int numTrees(int n) {
        
        return catalan(n);
    }
};
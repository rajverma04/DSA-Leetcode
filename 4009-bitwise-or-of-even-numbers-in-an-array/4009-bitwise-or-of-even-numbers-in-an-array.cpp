class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> evennumber;

        int bitwiseOR = 0;

        for(auto x : nums) {
            if(x % 2 == 0) {        // if x is even
                bitwiseOR = bitwiseOR | x;      // perform bitwise
            }
        }

        return bitwiseOR;
    }
};
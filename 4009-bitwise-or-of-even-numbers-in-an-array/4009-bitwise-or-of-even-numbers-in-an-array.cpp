class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int> evennumber;

        int bitwiseOR = 0;
        for(auto x : nums) {
            if(x % 2 == 0) {
                evennumber.push_back(x);
            }
        }

        for(auto x : evennumber) {
            bitwiseOR = bitwiseOR | x;
        }

        return bitwiseOR;
    }
};
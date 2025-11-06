class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto x : nums) {
            freq[x]++;
        }

        int ans;
        for(auto x : freq) {
            if(x.second == 1) {
                ans =  x.first;
            }
        }
        return ans;
    }
};
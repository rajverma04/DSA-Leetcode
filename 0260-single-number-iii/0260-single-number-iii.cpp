class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto x : nums) {
            freq[x]++;
        }
        vector<int> ans;
        for(auto it : freq) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
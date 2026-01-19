class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        unordered_map<int, int> mp;
        mp[0] = 1;
        int totalCount = 0;
        for(auto x : nums) {
            if(mp[x - k] > 0) {
                totalCount += mp[x - k];
            }
            mp[x]++;
        }

        return totalCount;
    }
};
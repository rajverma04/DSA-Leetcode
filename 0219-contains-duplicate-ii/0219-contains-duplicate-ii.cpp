class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hset;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hset.count(nums[i])) {       // duplicate present
                return true;
            }
            hset.insert(nums[i]);
            if(hset.size() > k) {   // remove the last visited ele. from the set
                hset.erase(nums[i - k]);
            }
        }
        return false;
    }
};
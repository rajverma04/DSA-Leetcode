class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int start = 0, end = 0, len = 0;

        while(end < nums.size()) {
            mp[nums[end]]++;
            
            while(mp[nums[end]] > k && start < end) {       // remove the element until the freq of element > k
                mp[nums[start]]--;
                start++;
            }
            len = max(len, end - start + 1);
            end++;
        }

        return len;
    }
};
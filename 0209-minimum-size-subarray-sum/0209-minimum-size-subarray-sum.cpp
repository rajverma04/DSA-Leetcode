class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int minSize = INT_MAX;
        int start = 0, end = 0, n = nums.size();
        int prefixSum = 0;
        while(end < n) {
            prefixSum += nums[end];
            while(prefixSum >= target && start <= end) {
                prefixSum -= nums[start];
                int currSize = end - start + 1;
                if(currSize <= minSize) {
                    minSize = currSize;
                }
                start++;
            }
            end++;
        }

        return minSize == INT_MAX ? 0 : minSize;
    }
};
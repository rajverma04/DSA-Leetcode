class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        int start = 0, end = 0, n = nums.size();
        int prefixSum = 0;
        while(end < n) {
            prefixSum += nums[end];
            while(prefixSum >= target && start <= end) {
                prefixSum -= nums[start];
                int currSize = end - start + 1;
                minSize = min(minSize, currSize);
                start++;
            }
            end++;
        }

        return minSize == INT_MAX ? 0 : minSize;
    }
};
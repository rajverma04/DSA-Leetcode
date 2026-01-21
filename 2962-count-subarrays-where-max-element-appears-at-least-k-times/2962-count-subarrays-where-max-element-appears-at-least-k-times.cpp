class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = nums[0];
        for(auto x : nums) {
            maxEle = max(maxEle, x);
        }

        int start = 0, end = 0, count = 0;
        long long total = 0;
        int n = nums.size();
        while(end < n) {
            if(nums[end] == maxEle) {
                count++;
            }
            while(count == k) {
                total += n - end;
                if(nums[start] == maxEle) {
                    count--;
                } 
                start++;
            }

            end++;
        }

        return total;
    }
};
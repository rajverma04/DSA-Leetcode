class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int start = 0, end = 0;
        int product = 1;
        int count = 0;

        while(end < size) {
            product *= nums[end];

            while(product >= k && start <= end) {
                product /= nums[start];
                start++;
            }
            count += end - start + 1;
            end++;

        }

        return count;
    }
};
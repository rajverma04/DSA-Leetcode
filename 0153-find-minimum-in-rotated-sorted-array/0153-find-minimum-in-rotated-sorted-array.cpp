class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, mid, end = nums.size() - 1, ans = nums[0];

        while(start <= end) {
            mid = start + (end - start) / 2;

            if(nums[mid] >= nums[0]) {
                start = mid + 1;
            } else {
                end = mid - 1;
                ans = nums[mid];
            }
        }

        return ans;
    }
};
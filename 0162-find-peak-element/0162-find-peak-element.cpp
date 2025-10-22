class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int start = 0, mid, end = nums.size() - 1;

        while(start < end) {
            mid = start + (end - start) / 2;

            if(nums[mid] > nums[mid + 1]) {     // if mid element is peak
                end = mid;      // peak in left half
            } else {
                start = mid + 1;    // peak in right half
            }

        }

        return start;
    }
};
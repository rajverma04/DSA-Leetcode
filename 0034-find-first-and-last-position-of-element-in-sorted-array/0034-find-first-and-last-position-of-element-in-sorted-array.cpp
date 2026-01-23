class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, mid, high = nums.size() - 1, first = -1, last = -1;
        
        // find first
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // find last
        low = 0, high = nums.size() - 1;
         while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        vector<int> arr(2);
        arr[0] = first;
        arr[1] = last;
        return arr;
    }
};
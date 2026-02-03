class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        // strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1 || i == n) return false;  // no increasing part

        //  strictly decreasing
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == n) return false;  // no decreasing part

        //  strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        return i == n;
    }
};

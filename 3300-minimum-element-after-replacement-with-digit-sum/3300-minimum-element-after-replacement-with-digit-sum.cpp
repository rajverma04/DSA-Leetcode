class Solution {
public:
    int sumOfDigit(int num) {
        int sum = 0;

        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = sumOfDigit(nums[i]);
            mini = min(mini, nums[i]);
        }

        return mini;
    }
};
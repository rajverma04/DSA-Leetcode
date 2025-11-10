class Solution {
public:
    // void find(vector<int> &nums, int i, int &sum, int curr_sum) {
    //     if(i >= nums.size()) {
    //         sum = max(sum, curr_sum);
    //         return;
    //     }

    //     find(nums, i + 2, sum, curr_sum + nums[i]);
    //     find(nums, i + 1, sum, curr_sum);
    // }

    int rob(vector<int>& nums) {
        int sum = 0, curr_sum = 0;

        // find(nums, 0, sum, curr_sum);
        for(int x : nums) {
            int curr = max(sum, curr_sum + x);
            curr_sum = sum;
            sum = curr;
        }
        return sum;
    }
};
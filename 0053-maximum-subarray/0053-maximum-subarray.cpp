// Kadane's Algorithm : The idea of Kadane's algorithm is to traverse over the array from left to right and for each element, 
// find the maximum sum among all subarrays ending at that element. 
// The result will be the maximum of all these values. 

class Solution {
public:
    vector<int> dp;
    int solve(int index, vector<int> &nums) {
        if(index == 0) {
            return nums[0];
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        // max of current element or previously calcucalated subarray
        return dp[index] = max(nums[index], nums[index] + solve(index - 1, nums));
    }


    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        dp.assign(n, -1);
        int ans = nums[0];
        // traversing over each element
        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};
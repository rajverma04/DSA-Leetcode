class Solution {
public:
    vector<int> dpMax, dpMin;
    int findMax(int idx, vector<int> &nums) {
        if(idx == 0) {
            return dpMax[idx] = nums[0];
        }

        if(dpMax[idx] != INT_MIN) {
            return dpMax[idx];
        }

        return dpMax[idx] = max(nums[idx], nums[idx] + findMax(idx - 1, nums));
    }

    int findMin(int idx, vector<int> &nums) {
        if(idx == 0) {
            return dpMin[idx] = nums[0];
        }

        if(dpMin[idx] != INT_MAX) {
            return dpMin[idx];
        }

        return dpMin[idx] = min(nums[idx], nums[idx] + findMin(idx - 1, nums));
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        dpMax.assign(n, INT_MIN);
        dpMin.assign(n, INT_MAX);

        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            maxSum = max(maxSum,  findMax(i, nums));
            minSum = min(minSum,  findMin(i, nums));
            sum += nums[i];
        }

        if(maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, sum - minSum);
    }
};
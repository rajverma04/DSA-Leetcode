class Solution {
public:
    vector<vector<int>> dp;
    int find(int idx, int prevIdx, int n, vector<int> &nums) {
        if(idx == n) {      // out of array boundary
            return 0;
        }
        if(dp[idx][prevIdx + 1] != -1) {
            return dp[idx][prevIdx + 1];
        }

        int len = 0 + find(idx + 1, prevIdx, n, nums);      // notTake
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            len = max(len, 1 + find(idx + 1, idx, n, nums));        // take
        }

        return dp[idx][prevIdx + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // since we cannot store -1 index for starting index we shifted 1 index forward
        // 0 = -1, 1 = 0, 2 = 1..... like that
        dp.assign(n, vector<int> (n + 1, -1));
        return find(0, -1, n, nums);
    }
};
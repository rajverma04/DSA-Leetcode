class Solution {
public:
    vector<int> dp;
    int find(int idx, int n, vector<int> &nums) {
        if(idx >= n - 1) {      // reached or crossed last index
            return 0;
        }

        if(nums[idx] == 0) {    // cannot jump further
            return INT_MAX;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = INT_MAX;
        for(int jump = 1; jump <= nums[idx]; jump++) {
            int res = find(idx + jump, n, nums);

            if(res != INT_MAX) {
                ans = min(ans, 1 + res);        // plus one because 1 step counted
            }
        }

        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return find(0, n, nums);
    }
};
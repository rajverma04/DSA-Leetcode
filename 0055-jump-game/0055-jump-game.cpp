class Solution {
public:
    vector<int> dp;
    bool find(int idx, int n, vector<int> & nums) {
        if(idx >= n - 1) {      
            return true;
        }
        
        if(dp[idx] != -1) {
            return dp[idx];
        }
        
        for(int jump = 1; jump <= nums[idx]; jump++) {
            if(find(idx + jump, n, nums)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        return find(0, n, nums);
    }
};
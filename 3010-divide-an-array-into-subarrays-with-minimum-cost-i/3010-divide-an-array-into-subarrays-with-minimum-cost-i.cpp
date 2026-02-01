class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // first element is always included need to find two minimum elment after 0 index
        
        // sort(nums.begin() + 1, nums.end());
        // return nums[0] + nums[1] + nums[2];
        int ans = INT_MAX;

        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans = min(ans, nums[i] + nums[j]);
            }
        }
        return  nums[0] + ans;
    }
};
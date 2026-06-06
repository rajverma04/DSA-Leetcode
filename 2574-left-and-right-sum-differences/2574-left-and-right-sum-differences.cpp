class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int leftSum = accumulate(nums.begin(), nums.begin() + i, 0);
            int rightSum = accumulate(nums.begin() + i + 1, nums.end(), 0);

            ans.push_back(abs(leftSum - rightSum));
        }

        return ans;
    }
};
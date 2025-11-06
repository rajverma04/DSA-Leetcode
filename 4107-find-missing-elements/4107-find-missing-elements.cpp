class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for(auto element : nums) {
            mn = min(mn, element);
            mx = max(mx, element);
        }

        vector<int> ans;
        for(int i = mn; i <= mx; i++) {
            bool isfound = false;
            for(int j = 0; j < nums.size(); j++) {
                if(i == nums[j]) {
                    isfound = true;
                }
            }
            if(!isfound) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
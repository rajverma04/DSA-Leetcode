class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = nums[0], max = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
            }
            if(nums[i] > max) {
                max = nums[i];
            }
        }

        vector<int> ans;
        for(int i = min; i <= max; i++) {
            // bool isfound = find(arr.begin(), arr.end(), i);
            // if(!isfound) {
            //     ans.push_back(i);
            // }
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
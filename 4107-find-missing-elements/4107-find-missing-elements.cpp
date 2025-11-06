class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for(auto element : nums) {
            mn = min(mn, element);
            mx = max(mx, element);
        }

        vector<int> ans;
        // for(int i = mn; i <= mx; i++) {
        //     bool isfound = false;
        //     for(int j = 0; j < nums.size(); j++) {
        //         if(i == nums[j]) {
        //             isfound = true;
        //         }
        //     }
        //     if(!isfound) {
        //         ans.push_back(i);
        //     }
        // }

        // M2 --> using unordered_set: Elements are unique(not in key:value pair present)
        unordered_set<int> arr(nums.begin(), nums.end());   // copying nums element into arr

        for(int i = mn; i <= mx; i++) {
            if(arr.find(i) == arr.end()) {      // if not found in arr
                ans.push_back(i);
            }
        }

        return ans;
    }
};
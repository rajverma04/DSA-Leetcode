class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0) {
            return ans;
        }
        deque<int> d;
        int i = 0, n = nums.size();
        for(i = 0; i < n && i < k; i++) {
            while(d.size() && nums[d.back()] < nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
        }

        ans.push_back(nums[d.front()]);
        if(k >= nums.size()) {
            return ans;
        }

        for(; i < n; i++) {
            if((i - k) == d.front()) {
                d.pop_front();
            }

            while(d.size() && nums[d.back()] < nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};
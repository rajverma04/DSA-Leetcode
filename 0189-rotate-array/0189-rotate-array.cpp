class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // O(n + k)
        // deque<int> dq;

        // for(auto x : nums) {
        //     dq.push_back(x);
        // }

        // while(k != 0) {
        //     int last = dq.back();
        //     dq.pop_back();
        //     dq.push_front(last);
        //     k--;
        // }

        // int i = 0;
        // while(!dq.empty()) {
        //     nums[i] = dq.front();
        //     dq.pop_front();
        //     i++;
        // }

        // M2 : using reverse(which itself uses two pointer)
        
        k %= n;     // base case: because when we do reverse it will go out of boundary

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
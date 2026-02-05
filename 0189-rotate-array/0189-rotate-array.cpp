class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        for(auto x : nums) {
            dq.push_back(x);
        }

        while(k != 0) {
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
            k--;
        }

        int i = 0;
        while(!dq.empty()) {
            nums[i] = dq.front();
            dq.pop_front();
            i++;
        }
    }
};
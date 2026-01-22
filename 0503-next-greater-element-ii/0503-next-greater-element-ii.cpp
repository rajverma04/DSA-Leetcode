class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(), -1);       // nge: next greater element
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top()]) {
                nge[st.top()] = nums[i % n];
                st.pop();
            }

            if(i < n) {
                st.push(i);
            }
        }

        return nge;
    }
};
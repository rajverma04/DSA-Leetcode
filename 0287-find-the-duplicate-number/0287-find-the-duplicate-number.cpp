class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int ans;
        for(auto it : nums) {
            if(st.find(it) != st.end()) {
                ans = it;
                break;
            }

            st.insert(it);
        }
        return ans;
    }
};
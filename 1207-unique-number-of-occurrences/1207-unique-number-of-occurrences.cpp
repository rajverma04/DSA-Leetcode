class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x : arr) {
            mp[x]++;
        }
        // for(auto it : mp) {      // O(n*n)
        //     for(auto x : mp) {
        //         if(it.first == x.first) {
        //             continue;
        //         } else if(it.second == x.second) {
        //             return false;
        //         }
        //     }
        // }

        unordered_set<int> st;
        for(auto it : mp) {
            if(st.count(it.second)) {
                return false;
            }
            st.insert(it.second);
        }
        
        return true;
    }
};
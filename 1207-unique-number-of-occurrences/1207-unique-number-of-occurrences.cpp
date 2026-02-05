class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x : arr) {
            mp[x]++;
        }
        for(auto it : mp) {
            for(auto x : mp) {
                if(it.first == x.first) {
                    continue;
                } else if(it.second == x.second) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
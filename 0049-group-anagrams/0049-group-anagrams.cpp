class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto st : strs) {
            string key = st;
            sort(key.begin(), key.end());

            mp[key].push_back(st);
        }

        vector<vector<string>> ans; 
        for(auto ele : mp) {
            ans.push_back(ele.second);
        }

        return ans;
    }
};
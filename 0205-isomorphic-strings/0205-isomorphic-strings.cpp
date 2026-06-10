class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp;
        unordered_set<char> used;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(!mp.count(ch)) {

                if(used.count(t[i]))
                    return false;

                mp[ch] = t[i];
                used.insert(t[i]);
            }
            else {

                if(mp[ch] != t[i])
                    return false;
            }
        }

        return true;
    }
};
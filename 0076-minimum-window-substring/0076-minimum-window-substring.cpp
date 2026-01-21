class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto ch : t) {
            mp[ch]++;
        }
        int total = t.size();
        int start = 0, end = 0, n = s.size();
        int ans = INT_MAX, index = -1;
        while(end < n) {
            mp[s[end]]--;       // decrese the count of char
            if(mp[s[end]] >= 0) {
                total--;
            }
            // decrese the size of window
            while(!total && start <= end) {
                if(ans > end - start + 1) {     // update the length of string
                    ans = end - start + 1;
                    index = start;
                }
                mp[s[start]]++;

                if(mp[s[start]] > 0) {      // if count is positive
                    total++;
                }
                start++;            // decrese the window size
            }
            end++;          // increse the size of window
        }
        
        if(index == -1) {
            return "";
        }
        string str = "";
        for(int i = index; i < index + ans; i++) {
            str += s[i];
        }

        return str;
    }
};
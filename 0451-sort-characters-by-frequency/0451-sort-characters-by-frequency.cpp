class Solution {
public:
    string frequencySort(string s) {
        priority_queue<
            pair<int, char>
        > q;

        unordered_map<char, int> freq;
        for(auto ch : s) {
            freq[ch]++;
        }

        string str = "";

        for(auto &p : freq) {
            q.push({p.second, p.first});
        }

        while(!q.empty()) {
            auto [count, ch] = q.top();
            q.pop();

            str.append(count, ch);
        }
        return str;
    }
};
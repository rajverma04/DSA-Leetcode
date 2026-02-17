class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            
            if(a.first == b.first)      // same freq
                return a.second > b.second; // lexicographically smaller first string
            
            return a.first < b.first; // higher frequency first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (auto str : words) {
            freq[str]++;
        }

        // max heap
        priority_queue<pair<int, string>, vector<pair<int,string>>, cmp> pq;        // {datatype, container, comparator}

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }
        vector<string> ans;

        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};
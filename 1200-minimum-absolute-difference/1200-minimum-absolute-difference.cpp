class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;         // {minDiff, {firstElement, secondElement}}
            sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            pq.push({arr[i] - arr[i - 1], {arr[i - 1], arr[i]}});
        }
        
        int mind = pq.top().first;
        vector<vector<int>> ans;
        while (!pq.empty() && pq.top().first == mind) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
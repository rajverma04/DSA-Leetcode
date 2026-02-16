class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;     // {score, index}

        for(int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        vector<string> ans(score.size());
        
        int rank = 1;
        while(!pq.empty()) {
            if(rank == 1) {
                ans[pq.top().second] = "Gold Medal";
            } else if(rank == 2) {
                ans[pq.top().second] = "Silver Medal";
            } else if(rank == 3) {
                ans[pq.top().second] = "Bronze Medal";
            } else {
                ans[pq.top().second] = to_string(rank);
            }
            rank++;
            pq.pop();
        }

        return ans;
    }
};
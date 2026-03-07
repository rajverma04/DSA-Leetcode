class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for(auto point : points) {
            int dist = point[0]*point[0] + point[1]*point[1];
            pq.push({dist, point[0], point[1]});
        }

        vector<vector<int>> ans;
        while(k--) {
            auto [sum, p1, p2] = pq.top();
            pq.pop();

            ans.push_back({p1, p2});
        }

        return ans;
    }
};
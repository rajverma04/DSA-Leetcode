class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++) {        // convert to normal graph
            for(int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
        priority_queue<     // weight, node
            pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int, int>> > pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});        // origin
        int cost = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();

            if(visited[node]) {
                continue;
            }
            visited[node] = true;
            cost += wt;

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjW = it.second;

                if(!visited[adjNode]) {
                    pq.push({adjW, adjNode});
                }
            }
        }

        return cost;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        vector<pair<int, int>> adj[n];      // node: {to, price}

        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<tuple<int, int, int>> q;      // {stop, node, cost}
        q.push({0, src, 0});
        dist[src] = 0;

        // Dijkastra Algorithm
        while(!q.empty()) {
            auto [stop, node, cost] = q.front();
            q.pop();
            
            if(stop > k) {
                continue;
            }

            for(auto it : adj[node]) {
                int adjNode = it.first;         // adjacent node
                int edgeW = it.second;           // edge weight

                if(cost + edgeW < dist[adjNode] && stop <= k) {
                    dist[adjNode] = cost + edgeW;
                    q.push({stop + 1, adjNode, cost + edgeW});
                }
            }
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};
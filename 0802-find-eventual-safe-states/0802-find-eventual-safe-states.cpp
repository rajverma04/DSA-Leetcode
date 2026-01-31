class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);     // reverese adj list
        for(int i = 0; i < V; i++) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }

        vector<int> inDeg(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDeg[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(!inDeg[i]) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i = 0; i < adj[node].size(); i++) {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
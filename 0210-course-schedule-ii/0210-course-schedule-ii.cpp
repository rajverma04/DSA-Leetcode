class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        vector<int> inDeg(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                inDeg[it]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        // Topological Sort
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i = 0; i < adj[node].size(); i++) {
                inDeg[adj[node][i]]--;      // decrese the indegree
                if(inDeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};

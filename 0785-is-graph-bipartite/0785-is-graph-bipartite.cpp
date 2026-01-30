class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();       // vertex
        queue<int> q;
        vector<int> color(V, -1);       // {-1: not colored, 0: red, 1: blue}
        
        for(int start = 0; start < V; start++) {
            if(color[start] == -1) {        // not colored
                q.push(start);

                color[start] = 0;       // red

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto nbr : graph[node]) {
                        if(color[nbr] == -1) {      // not colored
                            q.push(nbr);
                            color[nbr] = 1 - color[node];       // give color opposite to node        
                        } else if(color[nbr] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
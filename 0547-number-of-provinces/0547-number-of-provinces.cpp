class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int node) {
        if(visited[node]) {
            return;
        }

        visited[node] = true;
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i]) {
                DFS(isConnected, visited, i);
            }
        }

        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);

        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                count++;
                DFS(isConnected, visited, i);
            }
        }
        return count;
    }
};
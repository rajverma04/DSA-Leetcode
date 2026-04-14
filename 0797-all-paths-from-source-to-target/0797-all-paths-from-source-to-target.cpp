class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(node);       // current node added

        if(node == graph.size() - 1) {
            ans.push_back(path);
        } else {
            for(auto ngh : graph[node]) {
                dfs(ngh, graph, path, ans);
            }
        }

        path.pop_back();        // backtracking
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0, graph, path, ans);

        return ans;
    }
};
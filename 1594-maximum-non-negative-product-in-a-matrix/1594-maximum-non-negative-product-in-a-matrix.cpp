class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<long long, long long> bfs(int i, int j, vector<vector<int>>& grid,
                                  vector<vector<pair<long long,long long>>>& dp,
                                  vector<vector<bool>>& vis) {

        if(i < 0 || j < 0) return {LLONG_MIN, LLONG_MAX};

        if(i == 0 && j == 0) {
            return {grid[0][0], grid[0][0]};
        }

        if(vis[i][j]) return dp[i][j];

        auto left = bfs(i, j - 1, grid, dp, vis);
        auto up   = bfs(i - 1, j, grid, dp, vis);

        long long val = grid[i][j];
        vector<long long> v;

        if(left.first != LLONG_MIN) {
            v.push_back(left.first * val);
            v.push_back(left.second * val);
        }
        if(up.first != LLONG_MIN) {
            v.push_back(up.first * val);
            v.push_back(up.second * val);
        }

        long long mx = *max_element(v.begin(), v.end());
        long long mn = *min_element(v.begin(), v.end());

        vis[i][j] = true;
        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(r, vector<pair<long long,long long>>(c));
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        auto res = bfs(r - 1, c - 1, grid, dp, vis);

        return (res.first < 0 ? -1 : res.first % MOD);
    }
};
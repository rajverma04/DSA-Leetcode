class Solution {
public:
    int find(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i < 0) {         // s1 empty string ho gaya hai
            return j + 1;       // aur s2 me j + 1 char hai
        }
        if(j < 0) {         // s2 empty string ho gaya
            return i + 1;       // aur s2 me i + 1 char hai
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = find(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = 1 + min(                                  // 1 -> cost of performing one step
                                find(i - 1, j, s1, s2, dp),         // delete
                                min(
                                    find(i, j - 1, s1, s2, dp),     // insert 
                                    find(i - 1, j - 1, s1, s2, dp)) // replace
                                );
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return find(n - 1, m - 1, s1, s2, dp);
    }
};
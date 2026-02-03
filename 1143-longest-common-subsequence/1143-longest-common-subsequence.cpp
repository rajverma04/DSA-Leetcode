class Solution {
public:
    int find(int n, int m, string &text1, string &text2, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) {      // end of string
            return 0;       // longest string is 0(none)
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(text1[n - 1] == text2[m - 1]) {      // at both index char are equal then move index equally by 1
            return dp[n][m] = 1 + find(n - 1, m - 1, text1, text2, dp);     // +1 each char matched keep adding
        } else {
            // not matched then move one index and other keep at same and return max one
            return dp[n][m] = max(find(n - 1, m, text1, text2, dp), find(n, m - 1, text1, text2, dp));    // shrink one by one string
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // Top down
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return find(n, m, text1, text2, dp);

        // Bottom down
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};
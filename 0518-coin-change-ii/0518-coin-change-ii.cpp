class Solution {
public:
    int find(int index, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if(amount == 0) {
            return 1;
        }

        if(index < 0) {
            return 0;
        }
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int notTake = find(index - 1, amount, coins, dp);
        int take = 0;
        if(coins[index] <= amount) {        // coin agar remaining amount se jada ho jayega to nahi le sakte
            // usi index pe dubara check karenge kynki coins repeat le sakte hai
            take = find(index, amount - coins[index], coins, dp);       
        }
        
        return dp[index][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return find(n - 1, amount, coins, dp);
    }
};
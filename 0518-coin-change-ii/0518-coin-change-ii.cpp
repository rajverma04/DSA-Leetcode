class Solution {
public:
    // top down
    int find(int index, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        if(amount == 0) {
            return 1;
        }
        if(index < 0) {     // index out of boundary
            return 0;
        }
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int notTake = find(index - 1, amount, coins, dp);       // 
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





// Bottom up but not fully optimal as it signed integer overflow
// vector<vector<long long>> dp(n + 1, vector<long long> (amount + 1, 0));
//     dp[0][0] = 1;
//     for(int index = 1; index <= n; index++) {
//         for(int amt = 0; amt <= amount; amt++) {
//             long long notTake = dp[index - 1][amt];
//             long long take = 0;
//             if(coins[index - 1] <= amt) {
//                 take = dp[index][amt - coins[index - 1]];
//             }
//             dp[index][amt] = take + notTake;
//         }
//     }
// return (int)dp[n][amount];
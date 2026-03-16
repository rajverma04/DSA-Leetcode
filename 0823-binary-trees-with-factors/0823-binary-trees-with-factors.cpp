class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        unordered_map<int, int> index;
        for(int i = 0; i < arr.size(); i++) {       // storing the index of all element to get in O(1) time
            index[arr[i]] = i;
        }
        // x = a * b
        // x = b * a
        vector<long long> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {      //  x % a == 0
                    int right = arr[i] / arr[j];        // b = x / a
                    if(index.count(right)) {
                        int k = index[right];       // get index of b
                        dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for(auto x : dp) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};
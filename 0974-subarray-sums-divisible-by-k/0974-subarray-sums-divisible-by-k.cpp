class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int prefixSum = 0, rem;
        for(auto x : nums) {
            prefixSum += x;
            
            rem = prefixSum % k;

            if(rem < 0) {
                rem = rem + k;
            }
            if(mp.count(rem)) {     // count > 0
                ans += mp[rem];
                mp[rem]++;
            } else {
                mp[rem] = 1;
            }
        }

        return ans;
    }
};
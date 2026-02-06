class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n;                 // worst case: remove all
        int l = 0;

        for (int r = 0; r < n; r++) {
            // shrink window until condition holds
            while ((long long)nums[r] > (long long)nums[l] * k) {
                l++;
            }
            // window [l, r] is balanced
            ans = min(ans, n - (r - l + 1));
        }
        return ans;
    }
};

class Solution {
public:
    void solve(int num, vector<int> &ans) {
        vector<int> temp;
        while(num != 0) {
            int digit = num % 10;
            temp.push_back(digit);
            num /= 10;
        }

        reverse(temp.begin(), temp.end());
        for(auto x : temp) {
            ans.push_back(x);
        }
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto x : nums) {
            solve(x, ans);
        }

        return ans;
    }
};
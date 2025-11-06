class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0;
        for(auto x : nums) {
            freq[x]++;
        }

        for(auto pair : freq) {
            if(pair.second % k == 0) {      // if value is divisible by k
                sum += pair.first * pair.second;    // then calculate sum
            }
        }

        return sum;
    }
};
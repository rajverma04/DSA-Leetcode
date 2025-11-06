class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto x : nums) {
            freq[x]++;
        }

        int majorityElement = -1;
        for(auto x : freq) {
            if(x.second > nums.size() / 2) {
                majorityElement = x.first;
                break;
            }
        }

        return majorityElement;
    }
};
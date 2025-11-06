class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto x : nums) {
            freq[x]++;
        }

        bool duplicatePresent = false;
        for(auto x : freq) {
            if(x.second != 1) {
                duplicatePresent = true;
                break;
            }
        }

        return duplicatePresent;
    }
};
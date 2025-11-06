class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // M1 -->  unordered_set(contain distinct element)
        unordered_set<int> seen;
        for(auto x : nums) {
            if(seen.count(x)) {
                return true;        // duplicate present
            }
            seen.insert(x);
        }

        return false;       // duplicate not found

        // M2 --> freq method
        // unordered_map<int, int> freq;

        // for(auto x : nums) {
        //     freq[x]++;
        // }

        // bool duplicatePresent = false;
        // for(auto x : freq) {
        //     if(x.second != 1) {
        //         duplicatePresent = true;
        //         break;
        //     }
        // }

        // return duplicatePresent;
    }
};
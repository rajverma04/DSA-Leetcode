class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> freq;

        // for(auto x : nums) {
        //     freq[x]++;
        // }

        // int majorityElement = -1;
        // for(auto x : freq) {
        //     if(x.second > nums.size() / 2) {
        //         majorityElement = x.first;
        //         break;
        //     }
        // }

        // M2 : Moore's Voting algorithm
    
        int count = 0, element = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                element = nums[i];
            }
            if(nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }

        return element;
    }
};
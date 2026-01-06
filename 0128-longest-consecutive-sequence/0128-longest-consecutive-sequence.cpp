class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        // sort(nums.begin(), nums.end());

        int maxi = 0;
        // int count = 0;
        // for(int i = 0; i < nums.size() - 1; i++) {
        //     if((nums[i+1] - nums[i]) == 1) {
        //         count++;
        //     }

        //     if((nums[i+1] - nums[i]) > 1) {
        //         count = 0;
        //     }
        //     maxi = max(maxi, count);

        // }

        // return maxi+1;


        // M2: unordered_set
        unordered_set<int> st(nums.begin(), nums.end());

        for(auto num : st) {
            if(st.find(num - 1) == st.end()) {
                int currentNum = num;
                int count = 1;

                while(st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }
                maxi = max(maxi, count);

            }
        }

        return maxi;
    }
};
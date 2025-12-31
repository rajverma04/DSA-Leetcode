class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCons = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                maxCons = max(maxCons, count);
                count = 0;
            } else {
                count++;
            }
        }
        maxCons = max(maxCons, count);
        return maxCons;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int minnum = 1;     // smallest positive num
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minnum) {      // ignore negative 
                continue;
            } else if(nums[i] == minnum) {      // found current smallest, move to next
                minnum++;
            } else if(nums[i] > minnum) {   // gap found → missing number
                break;
            }
            
        }
        return minnum;
    }
};
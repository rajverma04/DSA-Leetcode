class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int zeroCount = 0;

        // calculate product of non-zero elements and count zeros
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeroCount++;
            } else {
                pro *= nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(zeroCount > 1) {
                nums[i] = 0;
            }
            else if(zeroCount == 1) {
                if(nums[i] == 0)
                    nums[i] = pro;
                else
                    nums[i] = 0;
            }
            else {
                nums[i] = pro / nums[i];
            }
        }

        return nums;
    }
};

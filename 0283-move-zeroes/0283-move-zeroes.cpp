class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // pointer for the non zero element

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {      // if the element is non zero
                swap(nums[i], nums[j]);     // move non zero element in front
                j++;
            }
        }
    }
};
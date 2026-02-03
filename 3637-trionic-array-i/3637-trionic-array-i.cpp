class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int phase = 0; // 0: inc, 1: dec, 2: inc
        bool inc1 = false, dec = false, inc2 = false;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return false;

            if (phase == 0) {
                if (nums[i] > nums[i - 1]) {
                    inc1 = true;
                } else {
                    phase = 1;
                    dec = true;
                }
            }
            else if (phase == 1) {
                if (nums[i] < nums[i - 1]) {
                    dec = true;
                } else {
                    phase = 2;
                    inc2 = true;
                }
            }
            else { // phase == 2
                if (nums[i] > nums[i - 1]) {
                    inc2 = true;
                } else {
                    return false;
                }
            }
        }

        return inc1 && dec && inc2;
    }
};

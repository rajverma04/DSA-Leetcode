class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {        // two element will always be unique or atmost 2 repeated
            return n;
        }
        int k = 2;
        for(int i = 2; i < n; i++) {
            // current element phle ke 2 element se different hai to replace kar do
            if(nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
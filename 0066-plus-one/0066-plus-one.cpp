class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;

        for(int i = n; i >= 0; i--) {
            if(digits[i] < 9) {     
                digits[i]++;
                return digits;
            }

            digits[i] = 0;      // if it's 9 → turn to zero and continue
        }

        digits.insert(digits.begin(), 1);       // If all digits were 9, we reach here
        return digits;
    }
};
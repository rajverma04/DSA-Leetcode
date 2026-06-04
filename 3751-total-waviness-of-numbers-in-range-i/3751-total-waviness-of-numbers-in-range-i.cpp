class Solution {
public:
    int solve(vector<int> &digit) {
        int wave = 0;

        for(int i = 1; i < digit.size() - 1; i++) {
            if(digit[i] > digit[i - 1] && digit[i + 1] < digit[i]) {    // peak
                wave++;
            }
            if(digit[i] < digit[i - 1] && digit[i + 1] > digit[i]) {   // valley
                wave++;
            }
        }
        
        return wave;
    }
    int totalWaviness(int num1, int num2) {
        
        int ans = 0;
        for(int i = num1; i <= num2; i++) {
            string s = to_string(i);
            vector<int> digit;

            for(auto ch : s) {
                digit.push_back(ch - '0');
            }
            
            ans += solve(digit);
        }

        return ans;
    }
};
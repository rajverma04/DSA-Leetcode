class Solution {
public:
    int countDivisor(int n) {
        int count = 1;
        for(int i = 2; i * i <= n; i++) {
            int power = 0;
            while(n % i == 0) {
                n /= i;
                power++;
            }
            if(power > 0) {
                count *= (power + 1);
            }
            if(count > 4) {
                break;
            }
        }
        
        if(n > 1) {
            count *= 2;
        }

        return count;
    }

    void divisorSum(int num, int &sum) {
        for(int i = 1; i * i <= num; i++) {
            if(num % i == 0) {
                sum += i;
                if(i != num / i) {
                    sum += num / i;
                }
            }
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        vector<int> ans;

        for(int it : nums) {
            int div = countDivisor(it);
            if(div == 4) {
                ans.push_back(it);
            }
        }

        int sum = 0;
        for(auto num : ans) {
            divisorSum(num, sum);
        }

        return sum;
    }
};
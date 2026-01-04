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
        }

        if(n > 1) {
            count *= 2;
        }

        return count;
    }

    void divisorSum(int num, int &sum) {
        // sum += 1;
        for(int i = 1; i <= num; i++) {
            if(num % i == 0) {
                sum += i;
                // num /= 10;
            }
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        vector<pair<int, int>> divisor;

        for(int it : nums) {
            int div = countDivisor(it);
            divisor.push_back({it, div});
        }

        vector<int> ans;
        for(auto it : divisor) {
            if(it.second == 4) {
                ans.push_back(it.first);
                // cout << it.first << " " << it.second;
            }
        }

        int sum = 0;
        for(auto num : ans) {
            divisorSum(num, sum);
            // cout << sum;
        }

        return sum;
    }
};
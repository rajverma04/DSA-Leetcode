class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0, totalGas = 0, start = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            if(totalGas < 0) {
                deficit += totalGas;
                totalGas = 0;
                start = i + 1;
            }
        }

        if(totalGas + deficit >= 0) {
            return start;
        }

        return -1;
    }
};
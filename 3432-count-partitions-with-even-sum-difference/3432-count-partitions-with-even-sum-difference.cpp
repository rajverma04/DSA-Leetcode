class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sumLeft = 0, sumRight = 0;
        int partitions = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            sumLeft += nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                sumRight += nums[j];
            }
            if(abs(sumLeft - sumRight) % 2 == 0) {
                partitions++;
            }
            sumRight = 0;
        }
        return partitions;
    }
};
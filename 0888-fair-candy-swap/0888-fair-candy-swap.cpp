class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (aliceSum - bobSum) / 2;
        int i = 0, j = 0;
        int n = aliceSizes.size();
        int m = bobSizes.size();
        vector<int> ans;

        while(i < n && j < m) {
            if(aliceSizes[i] - bobSizes[j] > diff) {
                j++;
            } else if (aliceSizes[i] - bobSizes[j] < diff) {
                i++;
            } else {        // aliceSizes[i] - bobSizes[j] == diff
                ans = {aliceSizes[i], bobSizes[j]};
                break;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int left = 0, right = 1;
        int n = arr.size();
        
        while (left < n) {
            right = left + 1;
            while (right < n) {
                if (arr[left] + arr[right] == target) {
                    return {left, right};
                }
                right++;
            }
            left++;
        }
        return {};
    }
};
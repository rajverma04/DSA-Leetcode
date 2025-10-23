class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxWater = 0;
        int left = 0, right = height.size() - 1;

        while(left < right) {
            // calculate area btw current pointer
            long long area = min(height[left], height[right]) * (right - left);
            maxWater = max(area, maxWater);

            // move the pointer with smaller pointer
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }
        return maxWater;
    }
};
class Solution {
public:
    vector<int> leftMemo, rightMemo;
    int maxLeft(vector<int> &height, int i) {
        if(i == 0) {
            return leftMemo[i] = height[i];
        }

        if(leftMemo[i] != -1) {
            return leftMemo[i];
        }

        return leftMemo[i] = max(height[i], maxLeft(height, i - 1));
    }

    int maxRight(vector<int> &height, int i) {
        int n = height.size();
        if(i == n - 1) {
            return rightMemo[i] = height[i];
        }

        if(rightMemo[i] != -1) {
            return rightMemo[i];
        }

        return rightMemo[i] = max(height[i], maxRight(height, i + 1));
    }
    
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) {
            return 0;
        }

        leftMemo.assign(n, -1), rightMemo.assign(n, -1);
        int water = 0;
        for(int i = 0; i < n; i++) {
            int leftMax = maxLeft(height, i);
            int rightMax = maxRight(height, i);

            water += min(leftMax, rightMax) - height[i];
        }

        return water;
    }
};
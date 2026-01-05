class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int it : nums) {
            pq.push(it);
        }

        int size = pq.size();
        for(int i = 0; i < size; i++) {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};
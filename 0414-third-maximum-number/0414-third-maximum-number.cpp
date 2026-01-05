class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // unique element storing
        unordered_set<int> set(nums.begin(), nums.end());

        priority_queue<int> pq;

        for(int x : set) {
            pq.push(x);
        }

        if(pq.size() < 3) {
            return pq.top();
        }
        
        pq.pop();
        pq.pop();

        return pq.top();
    }
};
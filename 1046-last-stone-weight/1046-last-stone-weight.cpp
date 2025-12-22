class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto x : stones) {
            pq.push(x);
        }

        while(pq.size() > 1) {
            int y = pq.top();       // greater element
            pq.pop();
            int x = pq.top();       // 2nd greater element  
            pq.pop();
            if(x == y) {
                continue;
            } else {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
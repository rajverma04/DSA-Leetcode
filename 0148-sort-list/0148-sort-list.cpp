/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        
        ListNode *temp = head;
        while(temp) {
            pq.push({temp->val, temp});
            temp = temp->next;
        } 

        temp = head;
        while(temp && !pq.empty()) {
            temp->val = pq.top().first;
            pq.pop();
            temp = temp->next;
        }

        return head;
    }
};
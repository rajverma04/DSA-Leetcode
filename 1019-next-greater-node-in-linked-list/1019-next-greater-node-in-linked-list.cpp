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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        ListNode *curr = head, *temp = head;

        while(curr) {
            int nextGreater = 0;
            while(temp) {
                if(temp->val > curr->val) {
                    nextGreater = temp->val;
                    break;
                }
                temp = temp->next;
            }
            ans.push_back(nextGreater);
            temp = curr->next;
            curr = curr->next;
        }
        // ans.push_back(0);
        return ans;
    }
};
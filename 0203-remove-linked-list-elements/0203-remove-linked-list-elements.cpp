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
    ListNode* removeElements(ListNode* head, int key) {
        // when headitself to be deleted
        while(head && head->val == key) {
            ListNode *deleteNode = head;
            head = head->next;
            delete deleteNode;
        }
        if(!head) {
            return head;
        }
        ListNode *prev = head;
        ListNode *temp = head->next;
        while(temp) {
            if(temp->val == key) {
                ListNode *deleteNode = temp;
                prev->next = temp->next;
                delete(temp);
                temp = prev->next;

            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;

    }
};
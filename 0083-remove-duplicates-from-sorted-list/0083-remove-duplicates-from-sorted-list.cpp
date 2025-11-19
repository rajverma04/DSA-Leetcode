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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }

        ListNode *temp = head;
        while(temp && temp->next) {     // temp and temp->next exist
            if(temp->val == temp->next->val) {
                ListNode *del_node = temp->next;    // delete temp->next element
                temp->next = temp->next->next;      // point temp->next->next
                delete del_node;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
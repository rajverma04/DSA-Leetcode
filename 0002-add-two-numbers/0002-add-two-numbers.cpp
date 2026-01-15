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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = new ListNode(0);
        ListNode *curr = sum;
        int carry = 0;
        while(l1 && l2) {
                int s = l1->val + l2->val + carry;
                carry = s / 10;
                ListNode *temp = new ListNode(s % 10);
                curr->next = temp;
                curr = curr->next;
                l1 = l1->next;
                l2 = l2->next;
        }
        while(l1) {
            int s = l1->val + carry;
            carry = s / 10;
            ListNode *temp = new ListNode(s % 10);
            curr->next = temp;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            int s = l2->val + carry;
            carry = s / 10;
            ListNode *temp = new ListNode(s % 10);
            curr->next = temp;
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
        }

        return sum->next;
    }
};
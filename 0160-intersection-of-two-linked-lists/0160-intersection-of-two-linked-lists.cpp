/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0, count2 = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1) {
            count1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            count2++;
            temp2 = temp2->next;
        }
        
        temp1 = headA, temp2 = headB;

        if(count1 > count2) {
            int skipNode = count1 - count2;
            while(skipNode != 0) {
                temp1 = temp1->next;
                skipNode--;
            }
        }
        if(count2 > count1) {
            int skipNode = count2 - count1;
            while(skipNode != 0) {
                temp2 = temp2->next;
                skipNode--;
            }
        }

        while(temp1 && temp2 && (temp1 != temp2)) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 && temp2) {
            return temp1;
        }
        return nullptr;
    }
};
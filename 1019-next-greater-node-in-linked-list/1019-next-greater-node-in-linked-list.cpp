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

        // M1: brute force(O(n*n))
        // vector<int> ans;

        // ListNode *curr = head, *temp = head;

        // while(curr) {
        //     int nextGreater = 0;
        //     while(temp) {
        //         if(temp->val > curr->val) {
        //             nextGreater = temp->val;
        //             break;
        //         }
        //         temp = temp->next;
        //     }
        //     ans.push_back(nextGreater);
        //     temp = curr->next;
        //     curr = curr->next;
        // }
        // return ans;


        // M2: stack(O(n))
        vector<int> values;
        for(ListNode *curr = head; curr; curr = curr->next) {
            values.push_back(curr->val);
        }
        int n = values.size();
        vector<int> ans(n, 0);      // store 0 initially for those whose nextGreater ele. does not exist
        stack<int> st;      // store the index of whose nextGreater element is not found

        for(int i = 0; i < n; i++) {
            while(!st.empty() && values[i] > values[st.top()]) {
                ans[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
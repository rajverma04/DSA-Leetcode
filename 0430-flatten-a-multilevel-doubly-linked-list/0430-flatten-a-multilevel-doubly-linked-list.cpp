/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void dfs(Node* head, Node *&prev) {
        if(!head) {
            return;
        }
        Node *next = head->next;

        prev->next = head;
        head->prev = prev;

        prev = head;

        if(head->child) {
            dfs(head->child, prev);
            head->child = NULL;
        }

        dfs(next, prev);
    }


    Node* flatten(Node* head) {
        if(!head) {
            return head;
        }
        
        Node* dummy = new Node();
        Node *prev = dummy;

        dfs(head, prev);
        
        Node *res = dummy->next;
        res->prev = NULL;
        return res;
    }
};
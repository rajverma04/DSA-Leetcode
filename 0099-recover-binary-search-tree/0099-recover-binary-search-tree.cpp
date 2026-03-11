/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 
    inorder traversal in BST make the element in sorted so find that tho element which is not sorted

*/
class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }

        inorder(root->left);
        if(prev && prev->val > root->val) {     // if prev val is greater than current root val it means element is not sorted
            if(!first) {    
                first = prev;       // store the first address which is not sorted
            }
            second = root;          // store the second element which is smaller 
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
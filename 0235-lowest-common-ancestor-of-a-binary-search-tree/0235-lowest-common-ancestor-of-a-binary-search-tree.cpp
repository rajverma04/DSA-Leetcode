/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root) {
        //     return nullptr;
        // }
        // // since its a BST
        // if(p->val < root->val && q->val < root->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // if(p->val > root->val && q->val > root->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }

        // return root;

        // Iterative method
        while(root) {

            if(p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if(p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};
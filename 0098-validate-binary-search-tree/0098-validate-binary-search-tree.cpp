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
class Solution {
public:

    void preorder(TreeNode *root, long long &prev, bool &ans) {
        if(!root || !ans) {
            return;
        }

        preorder(root->left, prev, ans);
        if(prev >= root->val) {
            ans = false;
            return;
        }
        prev = root->val;

        preorder(root->right, prev, ans);
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        bool ans = true;        // assuming tree in BST
        // to check BST in preorder all element are in ascending order means prev element must be greater than the current prorder element
        if(!root->left && !root->right) {
            return ans;
        }
        preorder(root, prev, ans);

        return ans;
    }
};
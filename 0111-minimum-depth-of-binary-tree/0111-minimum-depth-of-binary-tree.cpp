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
    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        // if one child is NULL : means one side tree is growing
        if(!root->left) {
            return 1 + dfs(root->right);
        }
        if(!root->right) {
            return 1 + dfs(root->left);
        }

        // if both child exist
        return 1 + min(dfs(root->left), dfs(root->right));
    }
    int minDepth(TreeNode* root) {
        
        return dfs(root);  
    }
};
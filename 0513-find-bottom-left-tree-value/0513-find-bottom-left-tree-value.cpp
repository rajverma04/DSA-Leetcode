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
    void dfs(TreeNode *root, int &maxDepth, int depth, int &ans) {
        if(!root) {
            return;
        }

        if(depth > maxDepth) {
            ans = root->val;
            maxDepth = depth;
        }

        dfs(root->left, maxDepth, depth + 1, ans);
        dfs(root->right, maxDepth, depth + 1, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int depth = 0;
        int ans = 0;
        dfs(root, maxDepth, depth, ans);
        return ans;
    }
};
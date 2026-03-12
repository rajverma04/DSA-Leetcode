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
    unordered_map<TreeNode*, int> dp;
    int find(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(dp.count(root)) {
            return dp[root];
        }
        int take = root->val;
        if(root->left) {
            take += find(root->left->left);
            take += find(root->left->right);
        }
        if(root->right) {
            take += find(root->right->right);
            take += find(root->right->left);
        }
        int notTake = 0 + find(root->left) + find(root->right);

        return dp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return find(root);
    }
};
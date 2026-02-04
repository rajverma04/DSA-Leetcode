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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return root;
        }
        // BFS
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()) {
        //     auto node = q.front();
        //     q.pop();

        //     swap(node->left, node->right);     // swap the address: it will automatically swap address and as well as value of its

        //     if(node->left) {
        //         q.push(node->left);
        //     }
        //     if(node->right) {
        //         q.push(node->right);
        //     }
        // }

        // M2: Using recurrsion
        TreeNode *node = root;
        swap(node->left, node->right);
        invertTree(node->left);
        invertTree(node->right);

        return root;
    }
};
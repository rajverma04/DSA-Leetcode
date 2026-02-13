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
    int getHeight(TreeNode* root) {
        if(!root) {
            return -1;
        }
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        
        int row = height + 1;
        int col = pow(2, height + 1) - 1;
        vector<vector<string>> ans(row, vector<string> (col, ""));

        queue<tuple<TreeNode*, int, int, int>> q;  // node, row, left range, right range
        q.push({root, 0, 0, col - 1});

        while(!q.empty()) {
            auto [node, row, left, right] = q.front();
            q.pop();
            int mid = (left + right) / 2;

            ans[row][mid] = to_string(node->val);
            
            if(node->left) {        // move left half
                q.push({node->left, row + 1, left, mid - 1});
            }
            if(node->right) {           // move right half
                q.push({node->right, row + 1, mid + 1, right});
            }
        }        
        return ans;
    }
};
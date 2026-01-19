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
        // Using DFS
        // return dfs(root); 

        // Using BFS
        if(!root) {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if(!node->left && !node->right) {
                return depth;
            }
            if(node->left) {
                q.push({node->left, depth + 1});
            }
            if(node->right) {
                q.push({node->right, depth + 1});
            }
        }

        return 0;
    }
};
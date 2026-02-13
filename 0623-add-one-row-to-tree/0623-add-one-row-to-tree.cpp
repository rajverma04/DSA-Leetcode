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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<pair<TreeNode*, int>> q;        // {root, level}
        q.push({root, 1});

        while(!q.empty()) {
            int level = q.front().second;
            int sz = q.size();
            auto temp = q.front().first;

            if(level == depth - 1) {
                for(int i = 0; i < sz; i++) {
                    TreeNode* node = q.front().first;
                    q.pop();

                    TreeNode* leftChild = node->left;
                    TreeNode* rightChild = node->right;

                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    node->left = newLeft;
                    node->right = newRight;

                    newLeft->left = leftChild;
                    newRight->right = rightChild;
                }
                break;
            } else {
                TreeNode *temp = q.front().first;
                q.pop();
                if(temp->left) {
                    q.push({temp->left, level + 1});
                }
                if(temp->right) {
                    q.push({temp->right, level + 1});
                }
            }


            // for(int i = 0; i < sz; i++) {
            //     TreeNode *temp = q.front().first;
            //     q.pop();
            //     if(temp->left) {
            //         q.push({temp->left, level + 1});
            //     }
            //     if(temp->right) {
            //         q.push({temp->right, level + 1});
            //     }
            // }
        }

        return root;
    }
};
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
    int getMinimumDifference(TreeNode* root) {
        if(!root) {
            return 0;
        }
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            arr.push_back(node->val);
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }

        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
            ans = min(ans, arr[i] - arr[i - 1]);
        }

        return ans;
    }
};
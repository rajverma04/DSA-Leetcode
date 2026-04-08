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
    string solve(TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &mp) {
        if(!root) {
            return "N";
        }

        string str = to_string(root->val) + "," + solve(root->left, ans, mp) + "," + solve(root->right, ans, mp);

        if(mp[str] == 1) {
            ans.push_back(root);
        }

        mp[str]++;
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> mp;

        solve(root, ans, mp);

        return ans;
    }
};
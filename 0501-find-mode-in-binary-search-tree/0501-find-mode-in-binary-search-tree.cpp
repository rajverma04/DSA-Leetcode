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
    unordered_map<int, int> freq;
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }

        freq[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        // if(!root->left && !root->right) {
        //     return {root->val};
        // }
        dfs(root);
        int mostFreq = 0;
        for(auto it : freq) {
            mostFreq = max(mostFreq, it.second);
        }

        for(auto it : freq) {
            if(it.second == mostFreq) {
                ans.push_back(it.first);
            }
        }
        // ans.push_back(mostFreq);
        return ans;
    }
};
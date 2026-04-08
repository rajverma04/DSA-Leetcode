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

/**
    Approach:

    1. We serialize each subtree into a string using preorder traversal 
       (root, left, right).

    2. Store each serialized string in a hash map (unordered_map) 
       to keep track of how many times a subtree has appeared.

    3. If a serialized string is already present in the map with frequency = 1,
       it means this subtree is seen for the second time → it's a duplicate,
       so we add its root to the answer.

    4. We use a delimiter (",") between values and "N" for NULL nodes 
       to ensure unique structure representation and avoid ambiguity.
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
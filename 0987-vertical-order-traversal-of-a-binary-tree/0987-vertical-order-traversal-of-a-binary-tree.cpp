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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        // for sorted column left to right
        map<int, map<int, multiset<int>>> mp;          // {col, {row, value}}

        if(!root) {
            return ans;
        }

        queue<pair<TreeNode*, pair<int, int>>> q;      // {node, column, row}
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first;
            int row = pos.second;

            mp[col][row].insert(node->val);
            if(node->left) {
                q.push({node->left, {col - 1, row + 1}});       // left col wrt root
            }
            if(node->right) {
                q.push({node->right, {col + 1, row + 1}});      // right col wrt root
            }
        }

        for(auto &col : mp) {
            vector<int> temp;
            for(auto row : col.second) {
                auto &val = row.second;
                // insert(position, startIterator, endIterator)
                temp.insert(temp.end(), val.begin(), val.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

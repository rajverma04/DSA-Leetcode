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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;          // used to find the root node as root node never be anyone child

        for(auto d : des) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // create node of each one
            if(!mp.count(parent)) {     
                mp[parent] = new TreeNode(parent);
            }
            if(!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childs.insert(child);   // store each child
        }

        // find root node
        for(auto d : des) {
            int parent = d[0];

            if(!childs.count(parent)) {
                return mp[parent];
            }
        }

        return nullptr;

    }
};
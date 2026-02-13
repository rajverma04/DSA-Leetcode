/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode * root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();      // parent
            q.pop();

            if(node->left) {
                parent[node->left] = node;     // child: node->left, and its parent is node 
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;     // child: node->right, and its parent is node 
                q.push(node->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);       // store parent node of each child

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);         // starting from target and apply BFS
        visited[target] = true;
        int distance = 0;

        while(!q.empty()) {
            int sz = q.size();

            if(distance == k) {
                break;
            }
            distance++;

            for(int i = 0; i < sz; i++) {
                auto node = q.front();      
                q.pop();

                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if(parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
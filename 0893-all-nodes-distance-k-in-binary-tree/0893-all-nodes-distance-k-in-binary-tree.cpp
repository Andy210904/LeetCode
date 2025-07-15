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
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& parents) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left != nullptr) {
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    void bfs(TreeNode* root, TreeNode* target, int k, map<TreeNode*, TreeNode*>& parents, unordered_set<TreeNode*>& visited, vector<int>& res) {
        if (target == nullptr || root == nullptr) {
            return;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist == k) {
                res.push_back(node->val);
            }
            if (parents.count(node) && !visited.count(parents[node])) {
                q.push({parents[node], dist + 1});
                visited.insert(parents[node]);
            }
            if (node->left && !visited.count(node->left)) {
                q.push({node->left, dist + 1});
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                q.push({node->right, dist + 1});
                visited.insert(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parents;
        markParents(root, parents);
        vector<int> res;
        unordered_set<TreeNode*> visited;
        bfs(root, target, k, parents, visited, res);
        return res;
    }
};

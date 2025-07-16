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
        map<int, vector<pair<int, int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; 
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;
            nodes[col].push_back({row, node->val});
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }
        vector<vector<int>> res;
        for (auto& [col, vec] : nodes) {
            sort(vec.begin(), vec.end());
            vector<int> colVals;
            for (auto& [row, value] : vec) {
                colVals.push_back(value);
            }
            res.push_back(colVals);
        }
        return res;
    }
};

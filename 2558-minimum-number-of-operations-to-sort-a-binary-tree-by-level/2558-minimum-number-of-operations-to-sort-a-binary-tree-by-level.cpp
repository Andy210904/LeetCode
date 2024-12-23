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
    int minimumSwaps(vector<int>& nums) {
        vector<pair<int, int>> indexed(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            indexed[i] = {nums[i], i};
        }
        sort(indexed.begin(), indexed.end());
        vector<bool> visited(nums.size(), false);
        int swaps = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || indexed[i].second == i) continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexed[j].second;
                cycleSize++;
            }
            swaps += (cycleSize - 1);
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            totalSwaps += minimumSwaps(levelValues);
        }

        return totalSwaps;
    }
};

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
    void inorder(TreeNode* root, vector<int>& sorted) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
    TreeNode* create(int left, int right, vector<int>& sorted) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(sorted[mid]);
        node->left = create(left, mid - 1, sorted);
        node->right = create(mid + 1, right, sorted);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return create(0, sorted.size() - 1, sorted);
    }
};

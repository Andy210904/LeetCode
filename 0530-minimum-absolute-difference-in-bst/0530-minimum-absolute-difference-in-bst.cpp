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
    void inorder(TreeNode* root,int& prev,int& diff){
        if(root == nullptr){
            return;
        }
        inorder(root->left,prev,diff);
        diff = min(diff,root->val - prev);
        prev = root->val;
        inorder(root->right,prev,diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        int prev = -1e9;
        inorder(root,prev,diff);
        return diff;
    }
};
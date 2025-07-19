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
    void build(TreeNode*& root,int val,TreeNode*target){
        if(root->val < val){
            if(root->right != nullptr){
                build(root->right,val,target);
            }
            else{
                root->right = target;
                return;
            }
        }
        else{
            if(root->left != nullptr){
                build(root->left,val,target);
            }
            else{
                root->left = target;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* target = new TreeNode(val);
        if(root == nullptr){
            return target;
        }
        build(root,val,target);
        return root;
    }
};
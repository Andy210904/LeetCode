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
    TreeNode* build(vector<int> pre,int& ind,int bound){
        if(ind == pre.size() || pre[ind] > bound){
            return nullptr;
        }
        TreeNode* curr = new TreeNode(pre[ind++]);
        curr->left = build(pre,ind,curr->val);
        curr->right = build(pre,ind,bound);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(preorder,ind,INT_MAX); 
    }
};
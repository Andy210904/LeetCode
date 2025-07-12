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
    TreeNode* build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& temp){
        if(prestart > preend || instart > inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = temp[root->val];
        int numsleft = inroot-instart;
        root->left = build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,temp);
        root->right = build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,temp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int m = preorder.size();
        map<int,int> temp;
        for(int i=0;i<n;i++){
            temp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder,0,m-1,inorder,0,n-1,temp);
        return root;
    }
};
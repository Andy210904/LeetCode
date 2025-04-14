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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            int n = temp.size();
            vector<int> t;
            for(int i=0;i<n;i++){
                TreeNode* curr = temp.front();
                temp.pop();
                t.push_back(curr->val);
                if(curr->left){
                    temp.push(curr->left);
                }
                if(curr->right){
                    temp.push(curr->right);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};
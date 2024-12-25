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
    void bfs(TreeNode*root,vector<int>& res){
        if(root == nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int max = INT_MIN;
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->val>max){
                    max = x->val;
                }
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
            res.push_back(max);
        }

    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        bfs(root,res);
        return res;
    }
};
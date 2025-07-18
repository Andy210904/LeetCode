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
    void markparents(TreeNode*root,int start,TreeNode*& target,map<TreeNode*,TreeNode*>& parents){
        if(root==nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start){
                target = curr;
            }
            if(curr->left != nullptr){
                q.push(curr->left);
                parents[curr->left] = curr;
            }
            if(curr->right != nullptr){
                q.push(curr->right);
                parents[curr->right] = curr;
            }
        }
    }
    int bfs(TreeNode* target,map<TreeNode*,TreeNode*>& parents){
        if(target == nullptr){
            return 0;
        }
        int time = -1;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> st;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (st.find(curr) != st.end()) {
                    continue;
                }
                st.insert(curr);
                if (curr->left != nullptr && st.find(curr->left) == st.end()) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr && st.find(curr->right) == st.end()) {
                    q.push(curr->right);
                }
                if (parents.find(curr) != parents.end() && st.find(parents[curr]) == st.end()) {
                    q.push(parents[curr]);
                }
            }
            time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target = new TreeNode(0);
        map<TreeNode*,TreeNode*> parents;
        markparents(root,start,target,parents);
        return bfs(target,parents);
    }
};
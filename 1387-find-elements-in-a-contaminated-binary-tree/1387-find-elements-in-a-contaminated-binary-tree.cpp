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
class FindElements {
public:
    set<int> temp;
    void dfs(TreeNode* root, stack<TreeNode*>& st) {
        if (root == nullptr) return;
        root->val = 0;
        temp.insert(root->val);
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            if (t->left) {
                t->left->val = 2 * t->val + 1;
                temp.insert(t->left->val);
                st.push(t->left);
            }
            if (t->right) {
                t->right->val = 2 * t->val + 2;
                temp.insert(t->right->val);
                st.push(t->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        stack<TreeNode*> st;
        dfs(root,st);
    }
    bool find(int target) {
        if(temp.find(target)!= temp.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
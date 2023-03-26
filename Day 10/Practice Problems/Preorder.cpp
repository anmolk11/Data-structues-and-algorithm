class Solution {
public:
    // [Iterative]
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return {};
        stack<TreeNode*> st;
        vector<int> out;
        st.push(root);
        while(!st.empty()) {
            TreeNode* top = st.top();
            out.push_back(top->val);
            st.pop();
            if (top->right)  st.push(top->right);
            if (top->left)  st.push(top->left);
        }
        return out;
    }
    
    // [Recursive]
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> pre;
    //     preorder(pre,root);
    //     return pre;
    // }
    // private:
    //     void preorder(vector<int>& pre, TreeNode* root) {
    //         if (!root)  return;
    //         pre.push_back(root->val);
    //         preorder(pre,root->left);
    //         preorder(pre,root->right);
    //     }
};
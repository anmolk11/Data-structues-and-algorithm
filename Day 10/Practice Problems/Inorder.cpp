class Solution {
public:
    // [Iterative]
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        stack<TreeNode*> st;
        vector<int> out;
        TreeNode* curr = root;
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            out.push_back(curr->val);
            curr = curr->right;
        }
        return out;
    }
    
    // [Recursive]
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> in;
    //     inorder(in,root);
    //     return in;
    // }
    // private:
    //     void inorder(vector<int>& in, TreeNode* root) {
    //         if (!root)  return;
    //         inorder(in,root->left);
    //         in.push_back(root->val);
    //         inorder(in,root->right);
    //     }
};
class Solution {
public:
//     [Iterative]
        vector<int> postorderTraversal(TreeNode* root) {    
            vector<int> out;
            stack<TreeNode*> todo;
            TreeNode* last = nullptr;
            TreeNode* curr = root;
            while (curr || !todo.empty()) {
                if (curr) {
                    todo.push(curr);
                    curr = curr -> left;
                } else {
                    TreeNode* node = todo.top();
                    if (node -> right && last != node -> right) {
                        curr = node -> right;
                    } else {
                        out.push_back(node -> val);
                        last = node;
                        todo.pop();
                    }
                }
            }
            return out;
        }

//     [Recursive]
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> post;
//         postorder(post,root);
//         return post;
//     }
// private:
//     void postorder(vector<int>& post, TreeNode* root) {
//         if(!root)   return;
//         postorder(post,root->left);
//         postorder(post,root->right);
//         post.push_back(root->val);
//     }
};
class Solution {
public:
bool isLeaf(TreeNode *root){
    return !root->left and !root->right;
}    

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        int x = root->val;

        if(isLeaf(root) and x == targetSum) return true; 

        return hasPathSum(root->left,targetSum - x) or hasPathSum(root->right,targetSum - x);
    }
};
class Solution {
public:
    int Ans = 0;
    void dfs(TreeNode *root,int sum){
        if(!root) return;
        
        int x = root->val;

        if(!root->left and !root->right){
            sum = sum * 10 + x;
            Ans += sum;
            return;
        }

        sum = sum * 10 + x;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return Ans;   
    }
};
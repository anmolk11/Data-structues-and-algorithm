class Solution {
public:
    vector<vector<int>> Ans;
    void dfs(vector<int>& nums,vector<int> &sol){
        int N = nums.size();
        if(N == 0){
            Ans.push_back(sol);
            return;
        }
        for(int i = 0;i < N;i++){
            sol.push_back(nums[i]);
            vector<int> newNums;
            for(int j = 0;j < N;j++){
                if(i != j) newNums.push_back(nums[j]);
            }
            dfs(newNums,sol);
            sol.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sol;
        dfs(nums,sol);
        return Ans;
    }
};
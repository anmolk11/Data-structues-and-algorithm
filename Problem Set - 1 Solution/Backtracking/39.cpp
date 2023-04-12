class Solution {
public:
    vector<vector<int>> Ans;

    void dfs(vector<int>& C, int T,int i,int curr,vector<int> &sol){
        int N = C.size();
        if(i == N) return;
        if(curr == T){
            Ans.push_back(sol);
            return;
        }

        if(C[i] + curr <= T){
            sol.push_back(C[i]);
            dfs(C,T,i,curr + C[i],sol);
            sol.pop_back();
        }
        dfs(C,T,i + 1,curr,sol);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        dfs(candidates,target,0,0,sol);
        return Ans;
    }
};
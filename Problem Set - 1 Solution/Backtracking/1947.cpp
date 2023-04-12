class Solution {
public:
    int Score(vector<int> &S,vector<int> &M){
        int scr = 0;
        for(int i = 0;i < S.size();i++){
            scr += (S[i] == M[i]);
        }
        return scr;
    }
    int dfs(vector<vector<int>>& S, vector<vector<int>>& M,int i,vector<bool> &taken){
        int N = S.size();
        if(i == N) return 0;

        int Ans = 0;

        for(int j = 0;j < N;j++){
            if(!taken[j]){
                taken[j] = 1;
                int scr = Score(S[i],M[j]);
                Ans = max(Ans,scr + dfs(S,M,i + 1,taken));
                taken[j] = 0;
            }
        }
        Ans = max(Ans,dfs(S,M,i + 1,taken));
        return Ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int N = students.size();
        vector<bool> taken(N,0);
        return dfs(students,mentors,0,taken);
    }
};
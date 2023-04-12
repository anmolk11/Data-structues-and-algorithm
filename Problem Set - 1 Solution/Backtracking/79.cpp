class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board, string word,int ind){
        int N = board.size(),M = board[0].size();

        if(ind == word.size()) return 1;

        if(i < 0 or j < 0 or i >= N or j >= M or board[i][j] == '.' or board[i][j] != word[ind]) return 0;

        char x = board[i][j];
        board[i][j] = '.';
        
        if(dfs(i + 1,j,board,word,ind + 1)) return 1;
        if(dfs(i - 1,j,board,word,ind + 1)) return 1;
        if(dfs(i,j + 1,board,word,ind + 1)) return 1;
        if(dfs(i,j - 1,board,word,ind + 1)) return 1;

        board[i][j] = x;

        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size(),M = board[0].size();
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(word[0] == board[i][j]){
                    if(dfs(i,j,board,word,0)) return 1;
                }
            }
        }
        return 0;
    }
};
// Problem link : https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    vector<vector<char>> Ans;
    bool rows(vector<vector<char>>& a){
        for(int i=0;i<9;i++){
            int h[10]={0};
            for(int j=0;j<9;j++){
                if(a[i][j]=='.') continue;
                if(h[a[i][j]-'0']!=0) return 0;
                else h[a[i][j]-'0']++; 
            }
        }
        return 1;
    } 

    bool column(vector<vector<char>>& a){
        for(int i=0;i<9;i++){
            int h[10]={0};
            for(int j=0;j<9;j++){
                if(a[j][i]=='.') continue;
                if(h[a[j][i]-'0']!=0) return 0;
                else h[a[j][i]-'0']++; 
            }
        }
        return 1;
    }

    bool box(vector<vector<char>>& a,int x,int y){
        int h[10]={0};
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(a[i][j]=='.') continue;
                if(h[a[i][j]-'0']!=0) return 0;
                else h[a[i][j]-'0']++; 
            }
        }
        return 1;
    }

    bool square(vector<vector<char>>& a){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!box(a,i,j)) return 0;
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return rows(board)&&column(board)&&square(board);
    }

    void solve(vector<vector<char>>& board,int i,int j){
        if(i == 9 and j == 0){
            Ans = board;
            return;
        }
        
        if(j == 8){
            if(board[i][j] != '.'){
                solve(board,i + 1,0);
            }
            else{
                for(int k = '1';k <= '9';k++){
                    board[i][j] = k;
                    if(isValidSudoku(board)){
                        solve(board,i + 1,0);
                    }
                    board[i][j] = '.';
                }
            }
        }
        else{
            if(board[i][j] != '.'){
                solve(board,i,j + 1);
            }
            else{
                for(int k = '1';k <= '9';k++){
                    board[i][j] = k;
                    if(isValidSudoku(board)){
                        solve(board,i,j + 1);
                    }
                    board[i][j] = '.';
                }
            }
        }
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        board = Ans;
    }
};
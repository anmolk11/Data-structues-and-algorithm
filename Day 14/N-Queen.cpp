// problem link : https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<vector<string>> Ans;
    bool checkRow(vector<string> &board,int i,int j){
        int N = board.size();
        int count = 0;
        for(int k = 0;k < N;k++){
            if(board[i][k] == 'Q') ++count;
        }
        return count == 1;
    }

    bool checkCol(vector<string> &board,int i,int j){
        int N = board.size();
        int count = 0;
        for(int k = 0;k < N;k++){
            if(board[k][j] == 'Q') ++count;
        }
        return count == 1;
    }

    bool checkDiagonal(vector<string> &board,int i,int j){
        int N = board.size();
        int x = i,y = j,count = 0;
        while(x >= 0 and y >= 0){
            if(board[x][y] == 'Q') ++count;
            --x;
            --y;
        }
        
        x = i,y = j;
        while(x < N and y < N){
            if(board[x][y] == 'Q') ++count;
            ++x;
            ++y;
        }

        if(count != 2) return false;

        count = 0;

        x = i,y = j;
        while(x < N and y >= 0){
            if(board[x][y] == 'Q') ++count;
            x++;
            y--;
        }
        
        x = i,y = j;
        while(x >= 0 and y < N){
            if(board[x][y] == 'Q') ++count;
            x--;
            y++;
        }
        if(count != 2) return false;

        return true;
    }

    bool valid(vector<string> &board,int i,int j){
       return checkRow(board,i,j) && checkCol(board,i,j) && checkDiagonal(board,i,j);
    }

    void dfs(vector<string> &board,int row  ){
        int N = board.size();

        if(row == N){
            Ans.push_back(board);
            return;
        }

        for(int j = 0;j < N;j++){
            board[row][j] = 'Q';
            if(valid(board,row,j)){
                dfs(board,row + 1);
            }
            board[row][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row(n,'.');
        vector<string> board(n,row);
        dfs(board,0);
        return Ans;
    }
};
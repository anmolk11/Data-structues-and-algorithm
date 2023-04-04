// Problem link : https://leetcode.com/problems/valid-sudoku/description/
class Solution {
public:
    bool rows(vector<vector<char>>& board){
        for(auto &i : board){
            int H[10] = {0};
            for(auto &j : i){
                if(j == '.') continue;
                if(H[j - '0']) return false;
                H[j - '0'] = 1;
            }
        }
        return true;
    }

    bool cols(vector<vector<char>>& board){
        for(int i = 0;i < 9;i++){
            int H[10] = {0};
            for(int j = 0;j < 9;j++){
                char c = board[j][i];
                if(c == '.') continue;
                if(H[c - '0']) return false;
                H[c - '0'] = 1;
            }
        }
        return true;
    }

    bool sqr(vector<vector<char>>& board,int i,int j){
        int H[10] = {0};
        for(int x = 0;x < 3;x++){
            for(int y = 0;y < 3;y++){
                char c = board[i + x][j + y];
                if(c == '.') continue;
                if(H[c - '0']) return false;
                H[c - '0'] = 1;
            }
        }
        return true;
    }

    bool box(vector<vector<char>>& board){
        for(int i = 0;i < 9;i += 3){
            for(int j = 0;j < 9;j += 3){
                if(!sqr(board,i,j)) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return rows(board) && cols(board) && box(board);
    }
};
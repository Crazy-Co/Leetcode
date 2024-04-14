#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board,int row,int col){
    // row and column
    for(int i=0; i<9; i++){
        if(board[row][col] == board[row][i] && col!=i) return false;
        if(board[row][col] == board[i][col] && row!=i) return false;
    }
    
    // grid
    int grid_row = (row/3) * 3;
    int grid_col = (col/3) * 3;
    for(int i=grid_row; i<grid_row+3; i++){
        for(int j=grid_col; j<grid_col+3; j++){
            if(board[row][col] == board[i][j] && (row!=i || col!=j)){
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<char>>& board,int row,int col){
    // base case
    if(row == board.size()) return true;


    // finding the next cell to fill
    int new_col=0, new_row=0;
    if(col != board.size()-1){
        new_row = row;
        new_col = col+1;
    }else{
        new_row = row+1;
        new_col = 0;
    }

    // solving sudoku
    if(board[row][col] != '.'){
        if(isValid(board,row,col)){
            if(solve(board,new_row,new_col)){
                return true;
            }
        }
    }
    else{
        if(solve(board,new_row,new_col)){
            return true;
        }
    }
    return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    return solve(board,0,0);
}

int main(){
    vector<vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout<<isValidSudoku(sudoku)<<endl;
    return 0;
}
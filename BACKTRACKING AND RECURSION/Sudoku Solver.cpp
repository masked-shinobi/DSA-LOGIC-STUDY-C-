#include <bits/stdc++.h>

using namespace std;

bool issafe(vector<vector<char>>& board, int row, int col, char digit){
    // horizontal
    for( int i = 0; i < 9; i++){
        if(board[row][i] == digit){
            return false;
        }
    }
    // vertical 
    for( int i = 0; i < 9; i++){
        if(board[i][col] == digit){
            return false;
        }
    }
    // grid rows
    int srow = (row/3) * 3;
    int scol = (col/3) * 3;
    for( int i = srow; i <= srow+2; i++){
        for( int j = scol; j <= scol+2; j++){
            if(board[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}

// algorithm
// base case - row is 9 then return true;
// calculate nextrow and nextcol  and if its 9 then the nextrow should be moved
// now if board[row and col] is not . which we have number there so we call the function returning board with next row and next col
// for loop dig we will check from 1 to 9 
    // if issafe then add the digit to board with digit at row and col
    // call sudoku with nextrow and nextcol and if that is true then return true
    // board row and column which we changed to digit make it to . again

// is safe function
// check number - to be 
// for 1->9 vertical and horizontal 
// grid row - with two loops - srow, scol
    // loop - srow -- srow+2
        // loop - scol -- scol+2
            // check the board digit

bool sudoku(vector<vector<char>>& board, int row, int col){

    if(row == 9) return true;

    int nextrow = row, nextcol = col+1;
    if(nextcol == 9){
        nextrow = row + 1;
        nextcol = 0;
    }

    if(board[row][col] != '.'){
        return sudoku(board, nextrow, nextcol);
    }

    for( char dig = '1'; dig <= '9'; dig++){
        if(issafe(board, row, col, dig)){
            board[row][col] = dig;
            if(sudoku(board, nextrow, nextcol)){
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solvesudoku(vector<vector<char>>& board){
    sudoku(board, 0, 0);
}

int main() {

    return 0;
}
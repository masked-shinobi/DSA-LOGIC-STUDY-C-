#include <bits/stdc++.h>

using namespace std;

// two methods to be used by the way 
bool issafe(vector<vector<char>>& board,int row,int col,int n){
    // check horizontal , vertical, diagonal 
    // for loop from 0 -> n check board[row][i] == Q
    // for loop from 0 -> n check board[i][col] == Q
    // for(i = row and j = col and then we reduce both one by one till 0 and then we check Q) - right diag
    // for(i = row and j = 0 and i > 0 and also check j < n and till i-- and j++)

            // all these conditions return false
    // horizontal 
    for( int i = 0 ; i < n; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }
    // vertical 
    for( int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    // left diagonal 
    for( int i = row, j = col; i >= 0 && j >= 0; i-- , j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // right diagonal
    for( int i = row, j = col; i >= 0 && j < n; i-- , j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void nQueen(vector<vector<char>>& board, int row, int n){
    // if row is n that is the end then we push to the board and then return -- basecase
    // for from 0 to n 
        // check is safe --( send row, j as column, board and the n ) then we place that row and the j as Q in the element
        // call the function with changing the row + 1
        // then backtrack the step making it again as . this would be the fail caseif
    if(row == n){
        // print board
        for( int i = 0 ; i < n; i++){
            for( int j =0 ; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for( int j = 0; j < n; j++){
        if(issafe(board, row, j, n)){
            board[row][j] = 'Q';
            nQueen(board, row+1, n);
            board[row][j] = '.';
        }
        
    }
}

void helper( vector<vector<char>>& board, int n){
    // since each time we need to give row and also n*n that n 
    // we are going to pass it inside function

    nQueen(board, 0, n);

}

int main() {

    // input would be board grid
    int n;
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n,'.'));

    helper(board,n);

    return 0;
}
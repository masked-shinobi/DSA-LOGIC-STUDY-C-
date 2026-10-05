#include <bits/stdc++.h>

using namespace std;

int main() {

    // input
    int m, n;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for ( int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }

    // print 
    for ( int i = 0; i < m; i++ ){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }

    // diagonal
    // primary diagonal
    for( int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            if(j == i){
                cout << mat[i][j];
            }
        }
    }
    // secondary diagonal 
    for( int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            if(j == n - i - 1){
                cout << mat[i][j];
            }
        }
    }   


    return 0;
}
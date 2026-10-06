// main recursion function
void ratmaze(vector<vector<int>>& mat, int r, int c, vector<string>& ans, string path, vector<vector<int>>& vis){

    int n = mat.size();
    // base case where we should come back without operation
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c]){
        return;
    }
    // add up the path which is the main base case for answer
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;
    // four direction call 
    ratmaze(mat, r+1, c, ans, path + "D", vis);
    ratmaze(mat, r-1, c, ans, path + "U", vis);
    ratmaze(mat, r, c-1, ans, path + "L", vis);
    ratmaze(mat, r, c+1, ans, path + "R", vis);

    // backtracking
    vis[r][c] = false;

}
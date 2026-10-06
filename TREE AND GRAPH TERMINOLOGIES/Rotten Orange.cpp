class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;
        // iterated throughout matrix
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0; i < m ; i++){
            for( int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.emplace(i, j);
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while(!q.empty() && fresh > 0){ // since this condition wont that give us infinite loop instead of stopping somewhere
            int size = q.size(); // i have doubt in this part how do you know that the q.size() would get the first iterative spread
            for( int i = 0; i < size; i++ ){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                for( int i = 0; i < 4; i++){
                    // generate the neighbours and then fresh rot
                    int nr = cx + dr[i];
                    int nc = cy + dc[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.emplace(nr, nc);
                    }
                }
            }
            minutes++;
        }
        // CONDITION
        if(fresh > 0){
            return -1;
        }else{
            return minutes;
        }
    }
};
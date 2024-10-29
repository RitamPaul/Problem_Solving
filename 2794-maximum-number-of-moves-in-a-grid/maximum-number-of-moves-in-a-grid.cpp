int dp[1000+1][1000+1];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int row, col, ans;
class Solution {
public:
    int f(vector<vector<int>>& grid, int x, int y){
        // base case
        
        // dp found case
        if(dp[x][y] != -1)
            return dp[x][y];
        
        // recursive case
        int maxi = 1;
        for(int k=0; k<3; ++k){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0<=nx and nx<row and 0<=ny and ny<col and grid[x][y]<grid[nx][ny])
                maxi = max(maxi, 1 + f(grid, nx, ny));
        }

        // return from current state
        return dp[x][y] = maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i=0; i<row; ++i)
            ans = max(ans, f(grid, i, 0) - 1);
        return ans;
    }
};
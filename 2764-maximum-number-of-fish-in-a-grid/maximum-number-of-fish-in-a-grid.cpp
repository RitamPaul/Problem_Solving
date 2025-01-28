int row, col, ans;
bool vis[10+1][10+1];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
class Solution {
public:    
    int helper(vector<vector<int>>& grid, int x, int y){
        vis[x][y]=true;
        int collected=grid[x][y];
        for(int k=0; k<4; ++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx and nx<row and 0<=ny and ny<col and !vis[nx][ny] and grid[nx][ny]>0)
                collected+=helper(grid, nx, ny);
        }
        return collected;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        ans=0;
        row=grid.size();
        col=grid[0].size();
        
        memset(vis, false, sizeof vis);
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(!vis[i][j] and grid[i][j]>0)
                    ans=max(ans, helper(grid, i, j));
            }
        }
        return ans;
    }
};
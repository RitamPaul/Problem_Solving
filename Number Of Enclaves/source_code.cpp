// User function Template for C++

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
class Solution {
  public:
    void mark(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &vis){
        int n = grid.size(), m = grid[0].size();
        // base case
        
        // recursive case
        // traversing all 4 directions
        for(int i=0; i<4; ++i){
            int ni = row + dx[i];
            int nj = col + dy[i];
            if(0<=ni and ni<n and 0<=nj and nj<m and grid[ni][nj]==1 and !vis[ni][nj]){
                vis[ni][nj] = true;
                mark(grid, ni, nj, vis);
            }
        }
        return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if((i==0 or i==n-1) and grid[i][j]==1 and !vis[i][j]){
                    vis[i][j] = true;
                    mark(grid, i, j, vis);
                }
                else if((j==0 or j==m-1) and grid[i][j]==1 and !vis[i][j]){
                    vis[i][j] = true;
                    mark(grid, i, j, vis);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1 and !vis[i][j])
                    ++ans;
            }
        }
        return ans;
    }
};
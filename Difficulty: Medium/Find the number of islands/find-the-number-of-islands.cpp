//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool vis[500+1][500+1];
int r;
int c;
int ans;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
class Solution {
  public:
    void func(vector<vector<char>>& grid, int x, int y){
        // base case
        
        vis[x][y] = true;
        for(int i=0; i<8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx and nx<r and 0<=ny and ny<c and grid[nx][ny]=='1' and !vis[nx][ny])
                func(grid, nx, ny);
        }
        return;
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        r=grid.size();
        c=grid[0].size();
        ans=0;
        memset(vis, 0, sizeof vis);
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(!vis[i][j] and grid[i][j]=='1'){
                    func(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
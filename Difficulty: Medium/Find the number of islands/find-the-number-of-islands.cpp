//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int row,col;
// l, r, u, d, lu, ld, ru, rd
int di[]={0,0,-1,1,-1,1,-1,1};
int dj[]={-1,1,0,0,-1,-1,1,1};
class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[i][j]=true;
        for(int k=0; k<8; ++k){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(0<=ni and ni<row and 0<=nj and nj<col
            and !vis[ni][nj] and grid[ni][nj]=='L')
                dfs(ni,nj,grid,vis);
        }
        return;
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        row=grid.size();
        col=grid[0].size();
        vector<vector<bool>> vis(row+1,vector<bool>(col+1,false));
        int ans=0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(!vis[i][j] and grid[i][j]=='L'){
                    dfs(i,j,grid,vis);
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
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
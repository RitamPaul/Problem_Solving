//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int row,col;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
class Solution {
  public:
    void dfs(int x, int y, vector<vector<int>>& arr, int pc, int nc, vector<vector<bool>> &vis){
        vis[x][y]=true;
        arr[x][y]=nc;
        for(int k=0; k<4; ++k){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx and nx<row and 0<=ny and ny<col and !vis[nx][ny] and arr[nx][ny]==pc)
                dfs(nx,ny,arr,pc,nc,vis);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        row=image.size();
        col=image[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col,false));
        dfs(sr,sc,image,image[sr][sc],newColor,vis);
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
class Solution {
  public:
    int row, col;
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        row=mat.size();
        col=mat[0].size();
        vector<vector<bool>> vis(row+1, vector<bool>(col+1,false));
        queue<pair<int,int>> q;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                // rotten found initially
                if(mat[i][j]==2){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int count=0;
        if(q.size())
            count=-1;
        while(q.size()){
            int nodes=q.size();
            // for initial count will be 0
            ++count;
            while(nodes--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(0<=nx and nx<row and 0<=ny and ny<col
                    and !vis[nx][ny] and mat[nx][ny]==1){
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                        mat[nx][ny]=2;
                    }
                }
            }
        }
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                // atleast single 1 found, couldn't be converted
                if(mat[i][j]==1)
                    return -1;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
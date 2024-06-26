//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0, ni, nj;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                for(int k=0; k<4; ++k){
                    ni = i + dx[k];
                    nj = j + dy[k];
                    if(matrix[i][j]==0 and 0<=ni and ni<n and 0<=nj and nj<m and matrix[ni][nj]==1)
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
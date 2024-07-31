//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

bool vis[5+1][5+1];
int n;
class Solution {
  public:
    void dfs(vector<vector<int>> &mat, int i, int j,
                vector<string> &ans, string &temp){
        vis[i][j] = true;
                    
        // base case
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
            vis[i][j] = false;
            return;
        }
        
        // recursive case
        // up
        if(0<=i-1 and mat[i-1][j]==1 and !vis[i-1][j]){
            temp.push_back('U');
            dfs(mat, i-1, j, ans, temp);
            temp.pop_back();
        }
        // down
        if(i+1<n and mat[i+1][j]==1 and !vis[i+1][j]){
            temp.push_back('D');
            dfs(mat, i+1, j, ans, temp);
            temp.pop_back();
        }
        // left
        if(0<=j-1 and mat[i][j-1]==1 and !vis[i][j-1]){
            temp.push_back('L');
            dfs(mat, i, j-1, ans, temp);
            temp.pop_back();
        }
        // right
        if(j+1<n and mat[i][j+1]==1 and !vis[i][j+1]){
            temp.push_back('R');
            dfs(mat, i, j+1, ans, temp);
            temp.pop_back();
        }
        
        vis[i][j] = false;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0] == 0)
            return {};
        
        n = mat.size();
        memset(vis, false, sizeof vis);
        
        vector<string> ans;
        string temp="";
        dfs(mat, 0, 0, ans, temp);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
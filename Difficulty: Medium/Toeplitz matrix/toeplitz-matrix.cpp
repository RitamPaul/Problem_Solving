//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n=mat.size(), m=mat[0].size(), ni, nj;
    for(int i=1; i<n; ++i){
        for(int j=0; j<m; ++j){
            ni=i-1, nj=j-1;
            if(0<=ni and ni<n and 0<=nj and nj<m and mat[ni][nj]!=mat[i][j])
                return false;
        }
    }
    return true;
}
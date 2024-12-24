//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int r=mat.size(), c=mat[0].size();
        if(x<mat[0][0] or x>mat[r-1][c-1])
            return false;
        
        int l=0, h=r-1, m, ans;
        while(l<=h){
            m=l+(h-l)/2;
            if(mat[m][c-1]>=x){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        l=0, h=c-1;
        while(l<=h){
            m=l+(h-l)/2;
            if(mat[ans][m]==x)
                return true;
            else if(mat[ans][m]>x)
                h=m-1;
            else
                l=m+1;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
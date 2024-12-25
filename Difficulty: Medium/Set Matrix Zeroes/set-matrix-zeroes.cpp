//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int r=mat.size(), c=mat[0].size();
        bool firstcell=false;
        bool firstcellonlyrow=false;
        bool firstcellonlycol=false;
        if(mat[0][0]==0)
            firstcell=true;
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                    
                    if(i==0)
                        firstcellonlyrow=true;
                    else if(j==0)
                        firstcellonlycol=true;
                }
            }
        }
        for(int i=1; i<r; ++i){
            for(int j=1; j<c; ++j){
                if(mat[i][0]==0 or mat[0][j]==0)
                    mat[i][j]=0;
            }
        }
        
        if(firstcell==true or firstcellonlyrow==true){
            for(int j=0; j<c; ++j)
                mat[0][j]=0;
        }
        if(firstcell==true or firstcellonlycol==true){
            for(int i=0; i<r; ++i)
                mat[i][0]=0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
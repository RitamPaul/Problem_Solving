//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int r=mat.size(), c=mat[0].size();
        // row iteration
        for(int i=0; i<r; ++i){
            int sum = 0;
            // col iterate : which row is celebrity
            for(int j=0; j<c; ++j)
                sum += mat[i][j];
            
            // if actualy that row is celebrity
            if(sum == 0){
                sum = 0;
                for(int row=0; row<r; ++row){
                    if(row!=i and mat[row][i]==1)
                        ++sum;
                }
                if(sum == r - 1)
                    return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
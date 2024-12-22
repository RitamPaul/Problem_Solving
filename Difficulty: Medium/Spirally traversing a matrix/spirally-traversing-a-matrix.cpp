//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int> ans;
        int row=mat.size(), col=mat[0].size();
        int l=0, r=col-1, u=0, d=row-1;
        while(true){
            // top row
            for(int k=l; k<=r; ++k)
                ans.push_back(mat[u][k]);
            ++u;
            
            // right col
            if(!(l<=r and u<=d))
                break;
            for(int k=u; k<=d; ++k)
                ans.push_back(mat[k][r]);
            --r;
            
            // down row
            if(!(l<=r and u<=d))
                break;
            for(int k=r; k>=l; --k)
                ans.push_back(mat[d][k]);
            --d;
            
            // left col
            if(!(l<=r and u<=d))
                break;
            for(int k=d; k>=u; --k)
                ans.push_back(mat[k][l]);
            ++l;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
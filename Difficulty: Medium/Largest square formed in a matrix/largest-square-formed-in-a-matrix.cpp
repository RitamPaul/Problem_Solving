//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans=0, height, breadth;
        stack<int> stk;
        for(int i=0; i<n; ++i){
            // addition from prev row
            for(int j=0; j<m; ++j){
                if(0<=i-1 and mat[i][j]==1)
                    mat[i][j] += mat[i-1][j];
            }
            
            // for all who have smaller item in its right
            for(int j=0; j<m; ++j){
                while(stk.size() and mat[i][j]<=mat[i][stk.top()]){
                    height = mat[i][stk.top()];
                    stk.pop();
                    if(stk.empty())
                        breadth = j;
                    else
                        breadth = j - stk.top() - 1;
                    
                    if(height <= breadth)
                        ans = max(ans, height);
                }
                stk.push(j);
            }
            // for all who haven't any smaller item in its right
            while(stk.size()){
                height = mat[i][stk.top()];
                stk.pop();
                if(stk.empty())
                    breadth = m;
                else
                    breadth = m - stk.top() - 1;
                
                if(height <= breadth)
                    ans = max(ans, height);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends
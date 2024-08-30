//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int mat[10+1][10+1];
class Solution{
public:
    bool safe(int row, int col, int n){
        // left horizontal
        for(int j=col-1; j>=0; --j){
            if(mat[row][j] == 1)
                return false;
        }
        
        // left up diagonal
        for(int i=row-1, j=col-1; (i>=0 and j>=0); --i, --j){
            if(mat[i][j] == 1)
                return false;
        }
        
        // left down diagonal
        for(int i=row+1, j=col-1; (i<n and j>=0); ++i, --j){
            if(mat[i][j] == 1)
                return false;
        }
        
        return true;
    }
    void f(int col, int n, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if(col >= n){
            ans.push_back(temp);
            return;
        }
        
        // recursive case
        for(int row=0; row<n; ++row){
            if(safe(row, col, n)){
                mat[row][col] = 1;
                temp.push_back(row+1);
                
                f(col+1, n, temp, ans);
                
                temp.pop_back();
                mat[row][col] = 0;
            }
        }
        return;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        memset(mat, 0, sizeof mat);
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        f(0, n, temp, ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
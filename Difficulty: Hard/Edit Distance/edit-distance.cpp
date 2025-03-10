//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n1, n2, dp[1000+1][1000+1];
    int f(int i, string &s1, int j, string &s2) {
        // base case
        if(i<0 and j<0)         return 0;
        if(i<0)                 return j+1;
        if(j<0)                 return i+1;
        
        // dp found case
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans=INT_MAX;
        // recursive case
        if(s1[i]==s2[j])
            ans = 0 + f(i-1, s1, j-1, s2);
        else {
            // insert
            ans = min(ans, f(i, s1, j-1, s2));
            // remove
            ans = min(ans, f(i-1, s1, j, s2));
            // replace
            ans = min(ans, f(i-1, s1, j-1, s2));
            // always +1 for doing given allowed steps
            ans = 1 + ans;
        }
        
        // return from current state
        return dp[i][j] = ans;
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        n1=s1.size();
        n2=s2.size();
        memset(dp, -1, sizeof dp);
        // memoisation
        return f(n1-1, s1, n2-1, s2);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
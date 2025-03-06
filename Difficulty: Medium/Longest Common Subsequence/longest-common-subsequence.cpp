//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n1, n2, dp[1000+1][1000+1];
    int f(int i, string &s1, int j, string &s2) {
        // base case
        if(i==0 or j==0)    return 0;
        // dp found case
        if(dp[i][j] != -1)  return dp[i][j];
        // recursive case
        int ans;
        if(s1[i-1]==s2[j-1])
            ans = 1 + f(i-1, s1, j-1, s2);
        else
            ans = 0 + max(f(i-1, s1, j, s2), f(i, s1, j-1, s2));
        // return from current state
        return dp[i][j] = ans;
    }
    int lcs(string &s1, string &s2) {
        // code here
        n1=s1.size();
        n2=s2.size();
        memset(dp, -1, sizeof dp);
        return f(n1, s1, n2, s2);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
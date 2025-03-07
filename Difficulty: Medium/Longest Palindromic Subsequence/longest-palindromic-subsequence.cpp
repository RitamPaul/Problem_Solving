//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

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
    int longestPalinSubseq(string &s) {
        // code here
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        n1=s1.size();
        n2=s2.size();
        memset(dp, -1, sizeof dp);
        // // memoisation
        // return f(n1, s1, n2, s2);
        
        // // tabulation
        // // base case
        // for(int i=0; i<=n1; ++i)
        //     dp[i][0] = 0;
        // for(int j=0; j<=n2; ++j)
        //     dp[0][j] = 0;
        // // recursive cases = opposite looping
        // for(int i=1; i<=n1; ++i){
        //     for(int j=1; j<=n2; ++j){
        //         if(s1[i-1]==s2[j-1])
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         else
        //             dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // // return final answer
        // return dp[n1][n2];
        
        // tabulation = space optimised
        vector<int> prev(n2+1), cur(n2+1);
        // base case
        for(int j=0; j<=n2; ++j)
            prev[j] = 0;
        cur[0] = 0;
        // recursive cases = opposite looping
        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                if(s1[i-1]==s2[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = 0 + max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        // return final answer
        return cur[n2];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
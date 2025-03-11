//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int n, vector<int> &dp) {
        if(n==0)        return 1;
        if(n<0)         return 0;
        
        if(dp[n]!=-1)   return dp[n];
        
        int ans = f(n-1, dp) + f(n-2, dp);
        
        return dp[n]=ans;
    }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        // memoisation
        return f(n, dp);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
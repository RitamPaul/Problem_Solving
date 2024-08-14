//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1000+1][1000+1];
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n1=s1.size(), n2=s2.size();
        int ans = 0;
        memset(dp, 0, sizeof dp);
        
        for(int i=0; i<n1; ++i){
            for(int j=0; j<n2; ++j){
                int diag = (0<=i-1 and 0<=j-1) ? dp[i-1][j-1] : 0;
                
                if(s1[i]==s2[j]){
                    if(0<=i-1 and 0<=j-1 and s1[i-1]==s2[j-1])
                        ans = max(ans, dp[i][j] = diag+1);
                    else
                        ans = max(ans, dp[i][j] = 1);
                }
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
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
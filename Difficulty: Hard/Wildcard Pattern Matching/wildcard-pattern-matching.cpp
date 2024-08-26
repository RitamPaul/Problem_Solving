//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n1, n2;
    int dp[200+1][200+1];
    int f(string &pat, string &str, int i, int j){
        // base case
        if(j>=n2){
            if(i>=n1)
                return 1;
            else if(pat[i] == '*'){
                int k;
                for(k=i; k<n1; ++k){
                    if(pat[k] != '*')
                        break;
                }
                // rest all are '*'
                if(k >= n1)
                    return 1;
                // rest all are not '*'
                else
                    return 0;
            }
        }
        if((i>=n1 and j<n2) or (i<n1 and j>=n2))
            return 0;
        
        // dp found case
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // recursive case
        int ans=0;
        // '?'
        if(pat[i] == '?'){
            ans = f(pat, str, i+1, j+1);
        }
        // '*'
        else if(pat[i] == '*'){
            for(int k=j; k<=n2; ++k){
                ans = f(pat, str, i+1, k);
                if(ans == 1)
                    break;
            }
        }
        // any alpha numeric value
        else{
            if(pat[i] == str[j])
                ans = f(pat, str, i+1, j+1);
        }
        
        // return from current state
        return dp[i][j] = ans;
    }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        n1=pattern.size();
        n2=str.size();
        memset(dp, -1, sizeof dp);
        return f(pattern, str, 0, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
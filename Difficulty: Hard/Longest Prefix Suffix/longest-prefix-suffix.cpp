//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

int lpsdp[(int)1e6 + 1];
class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.size();
        memset(lpsdp, 0, sizeof lpsdp);
        
        int pre=0, suf=1;
        while(suf < n){
            if(str[pre] == str[suf]){
                lpsdp[suf] = pre + 1;
                ++pre;
                ++suf;
            }
            else{
                if(pre == 0){
                    lpsdp[suf] = 0;
                    ++suf;
                }
                else
                    // pre = lpsdp[   lpsdp[suf-1]   ] - 1;
                    pre = lpsdp[pre-1];
            }
        }
        return lpsdp[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends
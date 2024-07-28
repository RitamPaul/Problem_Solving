//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

bool charmap[26];
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        memset(charmap, false, sizeof charmap);
        for(const auto &ch : str)
            charmap[ch-'a'] = true;
        
        string ans = "";
        for(const auto &ch : str){
            if(charmap[ch-'a']){
                ans += ch;
                charmap[ch-'a'] = false;
            }
        }
        return ans;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
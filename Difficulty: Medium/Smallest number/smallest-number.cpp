//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool helper(int s, int d, int place, string &ans){
        // base case
        if(place > d){
            if(s == 0)      return true;
            return false;
        }
        
        // calculation
        
        // recursion
        for(int digit=(place==1 ? 1 : 0); digit<=9; ++digit){
            ans += '0'+digit;
            bool result = helper(s-digit, d, place+1, ans);
            if(result)
                return true;
            ans.pop_back();
        }
        
        // backtracking
        return false;
    }
    string smallestNumber(int s, int d) {
        // code here
        string ans = "";
        helper(s, d, 1, ans);
        if(ans.empty())
            return "-1";
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
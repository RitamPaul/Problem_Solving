//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        string s = "";
        for(int i=0; i<32; ++i){
            if(x & (1<< i))
                s += '1';
            else
                s += '0';
        }
        reverse(s.begin(), s.end());
        
        unsigned long long ans = 0;
        unsigned long long mask = 1;
        for(int i=0; i<32; ++i){
            if(s[i] == '1')
                ans = ans + mask;
            mask = mask * 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
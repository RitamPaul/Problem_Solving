//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int n;
    string helper(string &s, int &ind){
        int num = 0;
        string given = "";
        while(ind < n and '0'<=s[ind] and s[ind]<='9'){
            num = (num * 10) + (int)(s[ind] - '0');
            ++ind;
        }
        ++ind;
        while(s[ind] != ']'){
            // letter found
            if('a'<=s[ind] and s[ind]<='z')
                given += s[ind];

            // number found
            if('0'<=s[ind] and s[ind]<='9'){
                given += helper(s, ind);
            }

            ++ind;
        }
        string ans = "";
        for(int i=1; i<=num; ++i){
            ans += given;
        }
        return ans;
    }
    string decodedString(string s) {
        n = s.size();
        int ind = 0;
        string ans = "";
        while(ind < n){
            // number found
            if('0'<=s[ind] and s[ind]<='9')
                ans += helper(s, ind);
            // alphabet found
            if('a'<=s[ind] and s[ind]<='z')
                ans += (char)s[ind];

            ++ind;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
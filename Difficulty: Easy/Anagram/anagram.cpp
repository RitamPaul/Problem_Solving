//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int first[26], second[26];
        memset(first, 0, sizeof first);
        memset(second, 0, sizeof second);
        
        for(const auto &ch : s1)
            ++first[ch - 'a'];
        
        for(const auto &ch : s2)
            ++second[ch - 'a'];
            
        for(int i=0; i<26; ++i){
            if(first[i] != second[i])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n;
    void helper(string &s, int ind, unordered_set<string> &st){
        // base case
        if(ind>=n){
            st.insert(s);
            return;
        }
        // recursive case
        for(int i=ind; i<n; ++i){
            swap(s[ind], s[i]);
            helper(s, ind+1, st);
            swap(s[i], s[ind]);
        }
        // return from current state
        return;
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        n=s.size();
        unordered_set<string> st;
        helper(s, 0, st);
        return vector<string> (st.begin(), st.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
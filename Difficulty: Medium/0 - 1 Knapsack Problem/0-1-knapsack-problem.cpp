//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[(int)1e3+1][(int)1e3+1];
    int n;
    int f(int W, vector<int>& wt, vector<int>& val, int ind){
        // base case
        if(ind >= n)
            return 0;
            
        // dp found case
        if(dp[W][ind] != -1)
            return dp[W][ind];
        
        // recursive case
        int pick=0, notpick=0;
        
        if(wt[ind] <= W)
            pick = val[ind] + f(W-wt[ind], wt, val, ind+1);
        
        notpick = 0 + f(W, wt, val, ind+1);
        
        // return from current state
        return dp[W][ind] = max(pick, notpick);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        n = wt.size();
        memset(dp, -1, sizeof dp);
        return f(W, wt, val, 0);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
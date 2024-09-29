//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int dp[10000+1];
int n;
class Solution {
  public:
    int f(int k, vector<int> &arr, int ind){
        if(ind >= n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int mini=INT_MAX;
        for(int i=1; i<=k and ind+i<n; ++i)
            mini = min(mini, abs(arr[ind]-arr[ind+i])+f(k, arr, ind+i));
        return dp[ind]=mini==INT_MAX ? 0 : mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        n=arr.size();
        memset(dp, -1, sizeof(dp));
        
        return f(k, arr, 0);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
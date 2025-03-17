//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int f(int ind, vector<int> &arr, vector<int> &dp) {
        int distToLast = n-(ind+1);
        if(ind<n-1 and arr[ind] >= distToLast)
            return dp[ind] = 1;
        if(ind == n-1)
            return dp[ind] = 0;
        if(arr[ind] == 0)
            return dp[ind] = INT_MAX;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ans=INT_MAX;
        for(int i=1; i<=arr[ind] and ind+i<n; ++i){
            ans = min(ans, f(ind+i, arr, dp));
        }
        // ending can be sucessfully reached from this index = take this index
        if(ans != INT_MAX)
            ans += 1;
        
        return dp[ind] = ans;
    }
    int minJumps(vector<int>& arr) {
        // code here
        // if(arr.front() == 0)
        //     return -1;
        n=arr.size();
        vector<int> dp(n+1, -1);
        int ans = f(0, arr, dp);
        return ans==INT_MAX ? -1 : ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
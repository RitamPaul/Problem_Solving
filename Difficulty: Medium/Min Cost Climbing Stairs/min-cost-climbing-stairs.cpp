//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int f(int ind, int n, vector<int> &cost, vector<int> &dp) {
        if(ind==n)      return 0;
        
        if(dp[ind]!=-1)     return dp[ind];
        
        int ans=INT_MAX;
        ans = min(ans, f(ind+1, n, cost, dp));
        if(ind+2 <= n)
            ans = min(ans, f(ind+2, n, cost, dp));
        ans = cost[ind] + ans;
        
        return dp[ind] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        // memoisation
        vector<int> dp(n+1, -1);
        return min(f(0,n,cost,dp), f(1,n,cost,dp));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
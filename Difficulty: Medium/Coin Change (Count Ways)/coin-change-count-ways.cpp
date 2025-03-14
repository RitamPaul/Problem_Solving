//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, vector<int>& coins, int sum,
    vector<vector<int>> &dp) {
        if(sum == 0)
            return 1;
        if(ind<0 and sum>0)
            return 0;
        
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        int pick=0, notpick=0;
        notpick = f(ind-1, coins, sum, dp);
        if(coins[ind]<=sum)
            pick = f(ind, coins, sum-coins[ind], dp);
        
        return dp[ind][sum] = pick + notpick;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return f(n-1, coins, sum, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, vector<int> &coins, int sum, vector<vector<int>> &dp) {
        if(sum == 0)
            return 0;
        if(ind<0)
            return INT_MAX;
        
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
            
        int pick=INT_MAX, notpick=INT_MAX;
        if(coins[ind]<=sum){
            pick = f(ind, coins, sum-coins[ind], dp);
            // picking this number will surely result to sum=0
            if(pick != INT_MAX)
                pick += 1;
        }
        notpick = 0 + f(ind-1, coins, sum, dp);
        
        return dp[ind][sum] = min(pick, notpick);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        if(sum==0)
            return 0;
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        int ans = f(n-1, coins, sum, dp);
        return ans==INT_MAX ? -1 : ans;
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
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
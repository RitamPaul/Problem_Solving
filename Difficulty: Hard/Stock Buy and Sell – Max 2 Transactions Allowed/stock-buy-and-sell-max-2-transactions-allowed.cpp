//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n, dp[100000+1][2+1][2];
    int f(int ind, vector<int>& prices, int prevbuy, int k) {
        // base case
        // all transaction completed - no opt to buy / sell
        if(k <= 0)
            return 0;
        // some transactions remained
        if(ind >= n) {
            // successfully sold previously bought
            if(!prevbuy)
                return 0;
            return (int)-1e8;
        }
        
        // dp found case
        if(dp[ind][k][prevbuy] != -1)
            return dp[ind][k][prevbuy];
        
        // recursive case
        long long pick=0, notpick=0;
        // Formula => Profit = Sell - Buy
        //                   = (-Buy) + (+Sell)
        // previously bought - time to sell
        if(prevbuy) {
            // sell this - 1 transaction complete
            pick = (long long)(+1*prices[ind]) + f(ind+1, prices, 0, k-1);
            notpick = (long long)f(ind+1, prices, prevbuy, k);
        }
        // buy this stock
        else {
            pick = (long long)(-1*prices[ind]) + f(ind+1, prices, 1, k);
            notpick = (long long)f(ind+1, prices, prevbuy, k);
        }
        
        // return from current state
        return dp[ind][k][prevbuy] = max(pick, notpick);
    }
    int maxProfit(vector<int> &prices) {
        // code here
        n=prices.size();
        memset(dp, -1, sizeof dp);
        // arguments = (index,
        //             prices, 
        //             previously no buy,
        //             total transaction count)
        return f(0, prices, 0, 2);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
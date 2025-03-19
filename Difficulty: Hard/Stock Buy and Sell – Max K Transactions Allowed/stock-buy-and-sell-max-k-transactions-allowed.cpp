//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n, dp[1000+1][200+1][2];
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
        int pick=0, notpick=0;
        // Formula => Profit = Sell - Buy
        //                   = (-Buy) + (+Sell)
        // previously bought - time to sell
        if(prevbuy) {
            // sell this - 1 transaction complete
            pick = (+1*prices[ind]) + f(ind+1, prices, 0, k-1);
            notpick = f(ind+1, prices, prevbuy, k);
        }
        // buy this stock
        else {
            pick = (-1*prices[ind]) + f(ind+1, prices, 1, k);
            notpick = f(ind+1, prices, prevbuy, k);
        }
        
        // return from current state
        return dp[ind][k][prevbuy] = max(pick, notpick);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        n=prices.size();
        memset(dp, -1, sizeof dp);
        // arguments = (index,
        //             prices, 
        //             previously no buy,
        //             total transaction count)
        return f(0, prices, 0, k);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
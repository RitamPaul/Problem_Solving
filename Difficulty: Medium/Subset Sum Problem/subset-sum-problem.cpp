//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp) {
        if(sum == 0)
            return true;
        if(ind < 0)
            return false;
        
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        bool pick=false, notpick=false;
        notpick = f(ind-1, arr, sum, dp);
        if(arr[ind] <= sum)
            pick = f(ind-1, arr, sum-arr[ind], dp);
        
        return dp[ind][sum] = pick | notpick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return f(n-1, arr, sum, dp);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
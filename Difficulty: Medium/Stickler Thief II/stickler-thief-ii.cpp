//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, vector<int> &arr, vector<int> &dp) {
        if(ind < 0)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int pick=0, notpick=0;
        notpick = 0 + f(ind-1, arr, dp);
        pick = arr[ind] + f(ind-2, arr, dp);
        
        return dp[ind] = max(pick, notpick);
    }
    int helper(vector<int> &arr) {
        int n=arr.size();
        vector<int> dp(n+1, -1);
        return f(n-1, arr, dp);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int> left, right;
        for(int i=0; i<n; ++i){
            if(i!=n-1)
                left.push_back(arr[i]);
            if(i!=0)
                right.push_back(arr[i]);
        }
        return max(helper(left), helper(right));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
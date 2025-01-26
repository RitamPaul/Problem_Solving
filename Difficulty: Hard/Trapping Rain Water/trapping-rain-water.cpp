//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n, ans;
    int helper(int ind, vector<int> &arr, int leftheightuptothis){
        // base case
        if(ind>=n)
            return 0;
        // entering recursion
        int curheight=arr[ind];
        int rightheightuptothis=helper(ind+1, arr, max(leftheightuptothis,arr[ind]));
        // backtracking calc
        int resultheight=min(leftheightuptothis,rightheightuptothis);
        int water=resultheight-curheight;
        if(water>=0)
            ans+=water;
        // return from current state
        return max(rightheightuptothis,arr[ind]);
    }
    int maxWater(vector<int> &arr) {
        // code here
        n=arr.size();
        ans=0;
        int dummy=helper(0, arr, 0);
        return ans;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
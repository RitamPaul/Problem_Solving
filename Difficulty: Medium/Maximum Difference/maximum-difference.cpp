//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leftsmall[(int)1e6+1];
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int ans = 0;
        memset(leftsmall, 0, sizeof leftsmall);
        stack<int> stk;
        
        // forming leftsmall array
        for(int i=0; i<n; ++i){
            while(stk.size() and arr[i]<=arr[stk.top()])
                stk.pop();
            
            if(stk.size())
                leftsmall[i] = arr[stk.top()];
            stk.push(i);
        }
        
        // emptying the stack to reuse it
        while(stk.size())
            stk.pop();
        
        // forming answer
        for(int i=n-1; i>=0; --i){
            while(stk.size() and arr[i]<=arr[stk.top()])
                stk.pop();
            
            int rightsmall = 0;
            if(stk.size())
                rightsmall = arr[stk.top()];
            
            ans = max(ans, abs(leftsmall[i] - rightsmall));
            stk.push(i);
        }
        
        return ans;
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
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
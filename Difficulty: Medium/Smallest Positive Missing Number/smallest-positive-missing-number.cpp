//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n=arr.size(), right=n;
        
        for(int i=n-1; i>=0; --i){
            if(arr[i] > 0){
                --right;
                swap(arr[i], arr[right]);
            }
        }
        
        for(int i=right; i<n; ++i){
            int cur = abs(arr[i]);
            if(0<=(right+cur-1) and (right+cur-1)<n and arr[right+cur-1]>0)
                arr[right+cur-1] *= -1;
        }
        
        int virtualind=0;
        for(; right+virtualind<n; ++virtualind){
            if(arr[right+virtualind] > 0)
                return virtualind+1;
        }
        return virtualind+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int max1=INT_MIN, max2=INT_MIN;
        for(int i=0; i<n; ++i){
            if(max1 < arr[i]){
                max2 = max(max2, max1);
                max1 = arr[i];
            }
            else
                max2 = max(max2, arr[i]);
        }
        return max1 + max2;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
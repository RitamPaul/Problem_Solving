//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n=arr.size(), l=0, h=n-1, m;
        while(l <= h){
            m = l + (h - l) / 2;
            if(arr[m] == key)
                return m;
            // (left is ascending and key is in left) or
            // (right is ascending and key is not in right)
            if((arr[l]<arr[m] and arr[l]<=key and key<arr[m]) or
                (arr[m]<arr[h] and (key<arr[m] or arr[h]<key)))
                h = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
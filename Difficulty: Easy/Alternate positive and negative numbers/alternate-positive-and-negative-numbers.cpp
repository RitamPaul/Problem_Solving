//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        vector<int> pos(n, INT_MAX), neg(n, INT_MAX);
        
        
        int i=0, j=0;
        for(const auto &item : arr){
            if(item >= 0)
                pos[i++] = item;
            else
                neg[j++] = item;
        }
        
        i = j = 0;
        for(int k=0; k<n; k+=2){
            arr[k] = pos[i]!=INT_MAX ? pos[i++] : neg[j++];
            if(k+1 < n)
                arr[k+1] = neg[j]!=INT_MAX ? neg[j++] : pos[i++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
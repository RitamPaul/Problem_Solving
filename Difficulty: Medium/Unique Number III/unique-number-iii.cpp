//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        vector<int> bit(32, 0);
        for(auto &i : arr){
            int num=i;
            for(int k=0; k<32; ++k){
                if(num & 1)
                    ++bit[k];
                num = num >> 1;
            }
        }
        int ans=0;
        for(int i=31; i>=0; --i){
            ans = ans << 1;
            if(bit[i]%3 == 1)
                ans = ans | 1;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
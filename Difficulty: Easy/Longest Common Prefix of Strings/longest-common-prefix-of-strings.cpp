//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans="";
        int n=INT_MAX;
        char comp;
        
        for(const auto &str : arr)
            n = min(n, (int)str.size());
        
        for(int i=0; i<n; ++i){
            comp = arr[0][i];
            for(const auto &str : arr){
                if(comp != str[i])
                    goto exit;
            }
            ans += comp;
        }
        
        exit:
        return (ans.empty() ? "-1" : ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
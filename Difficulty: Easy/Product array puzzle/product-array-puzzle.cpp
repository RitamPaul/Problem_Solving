//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long mul=1;
        bool onefound=false;
        int zerocount=0;
        for(auto &i : arr){
            if(i!=0)
                mul*=i;
            if(i==1)
                onefound=true;
            if(i==0){
                ++zerocount;
            }
        }
        for(auto &i : arr){
            if(i==0){
                i=mul;
                if(zerocount>1)
                    i*=0;
            }
            else{
                i=mul/i;
                if(zerocount)
                    i*=0;
            }
            if(i==1 and !onefound)
                i=0;
        }
        return arr;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
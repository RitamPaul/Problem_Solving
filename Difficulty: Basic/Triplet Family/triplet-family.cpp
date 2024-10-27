//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n=arr.size();
        int target, l, r;
        sort(arr.begin(), arr.end());
        for(int i=n-1; i>=2; --i){
            target = arr[i];
            l=0;
            r=i-1;
            while(l < r){
                if(arr[l]+arr[r] == target)
                    return true;
                else if(arr[l]+arr[r] > target)
                    --r;
                else
                    ++l;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
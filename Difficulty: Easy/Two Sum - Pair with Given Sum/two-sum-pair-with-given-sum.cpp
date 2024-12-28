//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int, vector<int>> mp;
        
        for(int i=0; i<arr.size(); ++i)
            mp[arr[i]].push_back(i);
        
        for(int i=arr.size()-1; i>=0; --i){
            int rem = target-arr[i];
            if(mp.count(rem)){
                if(rem==arr[i] and mp[arr[i]].size()>1)
                    return true;
                else if(rem!=arr[i])
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
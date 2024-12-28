//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, vector<int>> mp;
        int n=arr.size();
        
        for(int i=0; i<n; ++i)
            mp[arr[i]].push_back(i);
        
        int ans=0;
        for(int i=n-1; i>=0; --i){
            int rem = target-arr[i];
            if(mp.count(rem)){
                if(rem==arr[i]){
                    ans += mp[arr[i]].size()-1;
                }
                else
                    ans += mp[rem].size();
            }
            mp[arr[i]].pop_back();
            if(mp[arr[i]].empty())
                mp.erase(arr[i]);
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n=arr.size();
        unordered_map<int, pair<int,int>> mp;
        for(int i=0; i<n; ++i){
            // initialisation
            if(!mp.count(arr[i]))
                mp[arr[i]] = {INT_MIN, INT_MIN};
            // it is the first occurence
            if(mp[arr[i]].first == INT_MIN)
                mp[arr[i]].first = i;
            // it is the last occurence & always update it
            else
                mp[arr[i]].second = i;
        }
        int ans=0;
        for(const auto &p : mp){
            if(p.second.first!=INT_MIN and p.second.second!=INT_MIN)
                ans = max(ans, p.second.second-p.second.first);
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
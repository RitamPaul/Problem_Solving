//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size(), left=0;
        
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<n; ++i){
            if(arr[left][0] <= arr[i][0] and arr[i][0] <= arr[left][1]){
                arr[left][0] = min(arr[left][0], arr[i][0]);
                arr[left][1] = max(arr[left][1], arr[i][1]);
            }
            else{
                ++left;
                arr[left] = arr[i];
            }
        }
        
        return vector<vector<int>>(arr.begin(), arr.begin()+left+1);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
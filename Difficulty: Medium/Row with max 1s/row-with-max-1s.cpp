//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int r=arr.size(), c=arr[0].size();
        int i=0, j=c-1;
        int ansrow=-1, maxcount=INT_MIN, curcount;
        while(i<r and 0<=j){
            if(arr[i][j] == 1){
                curcount = c - j;
                if(maxcount < curcount){
                    maxcount = curcount;
                    ansrow = i;
                }
                --j;
            }
            else
                ++i;
        }
        
        return ansrow;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
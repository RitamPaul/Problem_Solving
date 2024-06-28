//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        string ans = "";
        bool found;
        int n = arr.size(), m = arr[0].size(), s, e;
        for(int i=0; i<n; ++i){
            s=0, e=m-1, found=true;
            while(s < e){
                if(arr[i][s] != arr[i][e]){
                    found = false;
                    break;
                }
                ++s;
                --e;
            }
            if(found){
                ans = to_string(i);
                ans += ' ';
                ans += 'R';
                break;
            }
        }
        if(found)       return ans;
        found = true;
        for(int j=0; j<m; ++j){
            s=0, e=n-1, found=true;
            while(s < e){
                if(arr[s][j] != arr[e][j]){
                    found = false;
                    break;
                }
                ++s;
                --e;
            }
            if(found){
                ans = to_string(j);
                ans += ' ';
                ans += 'C';
                break;
            }
        }
        if(found)       return ans;
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
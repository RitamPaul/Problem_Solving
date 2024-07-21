//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int maxn=LLONG_MIN;
        long long int ans = 1;
        long long int countp=0, countn=0, countz=0;
        long long int mod = 1e9 + 7;
        
        for(int i=0; i<arr.size(); ++i){
            // printf("(%lld-%lld-%lld)", ans, (long long)i, (long long)arr[i]);
            if(arr[i] < 0)                  ++countn;
            else if(arr[i] == 0)            ++countz;
            else                            ++countp;
            
            if(arr[i] != 0)
                ans = (ans * (long long int)arr[i]) % mod;
            if(arr[i] < 0)
                maxn = max(maxn, (long long int)arr[i]);
        }
        
        // printf("(+%lld, -%lld, %lld, ans-%lld) ", countp, countn, countz, ans);
        
        // 0 +ve integer
        if(countp == 0){
            if(countn > 1 and ans < 0)
                ans = ans / maxn;
            else if(countz)         return 0;
            
            if(ans != mod and ans > mod)
                return ans % mod;
            return ans;
        }
        // many +ve integer
        else{
            if(ans < 0)
                ans = ans / maxn;
            
            if(ans != mod and ans > mod)
                return ans % mod;
            return ans;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
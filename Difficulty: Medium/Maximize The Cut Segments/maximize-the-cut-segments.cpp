//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int dp[(int)1e4+1];
    int helper(int n, int x, int y, int z){
        // base case
        if(n == 0)
            return dp[n] = 0;
        if(n < min({x, y, z}))
            return dp[n] = -2;
        
        // dp found case
        if(dp[n] != -1)
            return dp[n];
        
        // recursive case
        int first{-2}, second{-2}, third{-2};
        if(x <= n){
            first = helper(n-x, x, y, z);
            if(first >= 0)
                first += 1;
        }
        if(y <= n){
            second = helper(n-y, x, y, z);
            if(second >= 0)
                second += 1;
        }
        if(z <= n){
            third = helper(n-z, x, y, z);
            if(third >= 0)
                third += 1;
        }
        
        // return from current state
        return dp[n] = max({first, second, third});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        int ans = helper(n, x, y, z);
        if(ans == -2)
            return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
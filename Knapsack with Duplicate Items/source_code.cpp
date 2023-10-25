// User function Template for C++

class Solution{
public:
    int helper(int w, int n, int val[], int wt[], vector<int> &dp){
        // base case
        if(w <= 0)  return 0;
        
        // dp found case
        if(dp[w] != -1)     return dp[w];
        
        // recursive case
        int maxi = 0;
        for(int i = 0; i < n; ++i){
            if(wt[i] <= w)
                maxi = max(maxi, val[i] + helper(w-wt[i], n, val, wt, dp));
        }
        
        // return from current state
        return dp[w] = maxi;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> dp(W+1, -1);
        return helper(W, N, val, wt, dp);
    }
};\
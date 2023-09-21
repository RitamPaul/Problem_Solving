class Solution
{
    public:
    int helper(int arr[], int n, int start, vector<int> &dp){
        // base case
        if(start == n-1)
            return dp[start] = arr[start];
        else if(start >= n)
            return 0;
        
        // dp found case
        if(dp[start] != -1)
            return dp[start];
        
        // recursive case
        int pick, notpick;
        pick = arr[start] + helper(arr, n, start+2, dp);
        notpick = helper(arr, n, start+1, dp);
        
        // return from current state
        return dp[start] = max(pick, notpick);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n){
        vector<int> dp(n+1, -1);
        return helper(arr, n, 0, dp);
    }
};
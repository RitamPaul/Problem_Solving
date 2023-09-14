class Solution{

	public:
	int mod = 1000000000+7;
	int helper(int arr[], int ind, int target, vector<vector<int>> &dp){
	    // base case
	    if(ind == -1){
	        if(target == 0)             return 1;
	        else                        return 0;
	    }
        if(target < 0)                  return 1;
        
        // dp found case
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        // recursive cases
        int take_child = 0, nottake_child = 0;
        // take that current item
        if(target >= arr[ind])
            take_child = helper(arr, ind-1, target-arr[ind], dp);
        // don't take that current item
        nottake_child = helper(arr, ind-1, target, dp);
        
        // return from current state
        return (dp[ind][target] = (take_child + nottake_child) % mod);
	}
	int perfectSum(int arr[], int n, int sum){
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	    return helper(arr, n-1, sum, dp);
	}
	  
};
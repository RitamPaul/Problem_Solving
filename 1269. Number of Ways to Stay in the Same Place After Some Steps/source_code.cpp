class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int helper(int steps, int ind, int n){
        // base case
        if(steps < 0)
            return 0;
        else if(steps == 0){
            if(ind == 0)
                return 1;
            else
                return 0;
        }
        
        // dp found case
        if(dp[ind][steps] != -1)
            return dp[ind][steps];

        // recursive case
        int ans = helper(steps-1, ind, n) % mod;
        if(0 <= ind - 1)
            ans = ((ans % mod) + (helper(steps-1, ind-1, n) % mod)) % mod;
        if(ind + 1 < n)
            ans = ((ans % mod) + (helper(steps-1, ind+1, n) % mod)) % mod;

        // return from current state
        return dp[ind][steps] = ans;
    }
    int numWays(int steps, int len) {
        len = min(steps, len);
        dp = vector<vector<int>> (len, vector<int>(steps+1, -1));
        return helper(steps, 0, len);
    }
};
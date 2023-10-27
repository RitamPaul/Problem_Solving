//User function template for C++

class Solution{
  public:
    int n;
    int lcss(string &ori, string &rev, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i >= n or j >= n)
            return 0;
        
        // dp found case
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // recursive case
        int ans = 0;
        if(ori[i] == rev[j])
            ans = 1 + lcss(ori, rev, i+1, j+1, dp);
        else
            ans = max(lcss(ori, rev, i, j+1, dp), 
                        lcss(ori, rev, i+1, j, dp));
        
        // return from curretn state
        return dp[i][j] = ans;
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        n = S.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string original = S;
        reverse(S.begin(), S.end());
        return n - lcss(original, S, 0, 0, dp);
    } 
};
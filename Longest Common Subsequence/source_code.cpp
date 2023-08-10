class Solution
{
    public:
    int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        //base case
        if(i>=s1.size() || j>=s2.size())
            return 0;
        
        //if answer found, just return it
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //recursive calls if character matches
        if(s1[i]==s2[j])
            return dp[i][j] = 1 + func(i+1, j+1, s1, s2, dp);
        
        //recursive calls if character not matches
        else
            return dp[i][j] = max( func(i+1, j, s1, s2, dp), func(i, j+1, s1, s2, dp) );
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2){
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return func(0,0,s1,s2,dp);
    }
};
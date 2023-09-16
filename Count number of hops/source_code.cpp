class Solution
{
    public:
    int mod = 1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n){
        vector<long long> dp(n+1);
        dp[0] = 1;
        long long one, two, three;
        for(int step=1; step<=n; ++step){
            //recursive case
            one = two = three = 0;
            if(step - 1 >= 0)       one = dp[step - 1];
            if(step - 2 >= 0)       two = dp[step - 2];
            if(step - 3 >= 0)       three = dp[step - 3];
            
            dp[step] = (one + two + three) % mod;
        }
        return dp[n];
    }
};
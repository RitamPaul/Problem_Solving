// User function Template for C++

class Solution{
public:
    int n;
    bool check(string &str, int start, int end){
        while(start <= end){
            if(str[start++] != str[end--])
                return false;
        }
        return true;
    }
    int helper(string &str, int start, vector<int> &dp){
        // base case
        if(start >= n)  return 0;
        
        // dp found case
        if(dp[start] != -1)
            return dp[start];
        
        // recursive case
        int cutcount = INT_MAX;
        for(int i = start; i < n; ++i){
            if(check(str, start, i) == true){
                cutcount = min(cutcount, 1 + helper(str, i+1, dp));
            }
        }
        
        // return from current state
        return dp[start] = cutcount;
    }
    int palindromicPartition(string str){
        n = str.size();
        vector<int> dp(n+1, -1);
        return helper(str, 0, dp) - 1;
    }
};
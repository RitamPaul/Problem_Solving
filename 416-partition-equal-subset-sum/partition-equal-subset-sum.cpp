class Solution {
public:
    int totalsum;
    bool f(int ind, vector<int> &arr, int cursum, vector<vector<int>> &dp) {
        if(cursum == (totalsum-cursum))
            return true;
        if(ind<0)
            return false;
        
        if(dp[ind][cursum] != -1)
            return dp[ind][cursum];
        
        bool pick=false, notpick=false;
        notpick = f(ind-1, arr, cursum, dp);
        pick = f(ind-1, arr, cursum+arr[ind], dp);
        
        return dp[ind][cursum] = pick | notpick;
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        totalsum=0;
        for(auto &i : arr)
            totalsum += i;
        vector<vector<int>> dp(n+1, vector<int>(totalsum+1, -1));
        return f(n-1, arr, 0, dp);
    }
};
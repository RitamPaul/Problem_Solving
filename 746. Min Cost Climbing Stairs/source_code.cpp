class Solution {
public:
    int helper(vector<int> &cost, int ind, vector<int> &dp){
        int n = cost.size();
        // base case
        if(ind >= n)
            return 0;

        // dp found case
        if(dp[ind] != -1)
            return dp[ind];

        // recursive case
        int one = helper(cost, ind+1, dp);
        int two = helper(cost, ind+2, dp);

        // return from current state
        return dp[ind] = cost[ind] + min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }
};
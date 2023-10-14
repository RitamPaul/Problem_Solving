class Solution {
public:
    int mincost(vector<int>& cost, vector<int>& time, int ind, int remwall, vector<vector<int>> &dp){
        int n = cost.size();
        // base case
        if(remwall <= 0)
            return 0;
        if(ind >= n)
            return 1e9;

        // dp found case
        if(dp[ind][remwall] != -1)
            return dp[ind][remwall];

        // recursive case
        int takeit, leaveit;
        takeit = cost[ind] + mincost(cost, time, ind+1, remwall-(1+time[ind]), dp);
        leaveit = mincost(cost, time, ind+1, remwall, dp);

        // return from current state
        return dp[ind][remwall] = min(takeit, leaveit);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return mincost(cost, time, 0, n, dp);
    }
};
class Solution {
public:
    int row, col, target;
    int f(int row, vector<vector<int>>& mat, int sum, vector<vector<int>> &dp){
        if(row<0)
            return abs(this->target - sum);

        if(dp[row][sum] != -1)
            return dp[row][sum];

        int ans=INT_MAX;
        for(int j=0; j<col; ++j)
            ans = min(ans, f(row-1, mat, sum+mat[row][j], dp));

        return dp[row][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->row=mat.size();
        this->col=mat[0].size();
        this->target = target;
        int possiblesum=0;
        for(auto &v : mat){
            for(auto &i : v)
                possiblesum += i;
        }
        vector<vector<int>> dp(row, vector<int>(possiblesum+1, -1));
        return f(row-1, mat, 0, dp);
    }
};
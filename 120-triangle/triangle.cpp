class Solution {
public:
    int totalrow, maxcol;
    int f(int currow, int curcol, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        int totalrow = triangle.size();
        if(currow >= totalrow)
            return 0;

        if(dp[currow][curcol] != -1)
            return dp[currow][curcol];
        
        int ans = triangle[currow][curcol]
                + min(f(currow+1, curcol, triangle, dp), f(currow+1, curcol+1, triangle, dp));
        
        return dp[currow][curcol] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        totalrow = triangle.size();
        maxcol = triangle[totalrow-1].size();
        vector<vector<int>> dp(totalrow+1, vector<int>(maxcol+1, -1));
        return f(0, 0, triangle, dp);
    }
};
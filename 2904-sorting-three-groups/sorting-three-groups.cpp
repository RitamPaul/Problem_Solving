int dp[100+1][3+1];
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), maxi;
        memset(dp, 0, sizeof(dp));
        dp[0][nums[0]] = 1;
        for(int i=1; i<n; ++i){
            // copy prev dp row
            for(int col=0; col<4; ++col)
                dp[i][col] = dp[i-1][col];
            
            // maximum
            maxi = INT_MIN;
            for(int col=1; col<=nums[i]; ++col)
                maxi = max(maxi, dp[i][col]);
            
            dp[i][nums[i]] = maxi + 1;
        }
        int maxchain = max({dp[n-1][1], dp[n-1][2], dp[n-1][3]});
        return n - maxchain;
    }
};
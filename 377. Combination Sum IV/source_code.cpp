class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int>& dp){
        // base case
        if(target == 0)         return 1;
        if(target < 0)          return 0;

        // dp found case
        if(dp[target] != -1)
            return dp[target];
        
        // calling for every possible solution
        int ways=0;
        for(int i=0; i<nums.size(); ++i)
            ways = ways + helper(nums, target-nums[i], dp);
        
        return dp[target] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, dp);
    }
};
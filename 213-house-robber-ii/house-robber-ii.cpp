class Solution {
public:
    int f(int ind, vector<int> &arr, vector<int> &dp) {
        if(ind < 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int notpick=0, pick=0;
        notpick = 0 + f(ind-1, arr, dp);
        pick = arr[ind] + f(ind-2, arr, dp);

        return dp[ind] = max(notpick, pick);
    }
    int helper(vector<int> &arr) {
        int n=arr.size();
        vector<int> dp(n+1, -1);
        return f(n-1, arr, dp);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> left, right;
        for(int i=0; i<n; ++i){
            if(i!=n-1)
                left.push_back(nums[i]);
            if(i!=0)
                right.push_back(nums[i]);
        }
        printf("left=[");
        for(auto &i : left)
            printf("%d,",i);
        printf("] \nright=[");
        for(auto &i : right)
            printf("%d,",i);
        printf("]");
        return max(helper(left), helper(right));
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxLeft(n,nums[0]), maxRight(n,nums[n-1]);
        for(int i=1; i<n; ++i)
            maxLeft[i]=max(nums[i],maxLeft[i-1]);
        for(int i=n-2; i>=0; --i)
            maxRight[i]=max(nums[i],maxRight[i+1]);
        long long ans=INT_MIN;
        for(int i=1; i<n-1; ++i)
            ans=max(ans,( ((long long)maxLeft[i-1]-nums[i])*maxRight[i+1] ));
        if(ans<0)
            return 0;
        return ans;
    }
};
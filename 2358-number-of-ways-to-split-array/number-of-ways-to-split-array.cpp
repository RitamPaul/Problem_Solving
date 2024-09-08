class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n=nums.size(), total = 0;

        for(const auto &i : nums)
            total += i;
        
        long long ans = 0, leftsum = 0;
        for(int i=0; i<n-1; ++i){
            leftsum += nums[i];
            long long rightsum = total - leftsum;

            if(leftsum >= rightsum)
                ++ans;
        }
        return ans;
    }
};
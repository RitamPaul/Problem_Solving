class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = INT_MIN;

        for(int i=0; i<n; ++i){
            if(nums[i] == maxi){
                int start = i;
                while(i<n and nums[i]==maxi)
                    ++i;
                ans = max(ans, i-start);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; ++i){
            if(i>0 and nums[i] == nums[i-1])
                continue;

            int target = (-1 * nums[i]);
            int l = i+1, r = n-1;
            while(l < r){
                if(l>i+1 and nums[l]==nums[l-1]){
                    ++l;
                    continue;
                }
                if(nums[l] + nums[r] == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                }
                else if(nums[l] + nums[r] > target)
                    --r;
                else
                    ++l;
            }
        }
        return ans;
    }
};
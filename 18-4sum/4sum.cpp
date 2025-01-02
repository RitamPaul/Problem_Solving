class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<=3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; ++i){
            if(i>0 and nums[i]==nums[i-1])  continue;
            for(int j=i+1; j<n-2; ++j){
                if(j>i+1 and nums[j]==nums[j-1])    continue;
                int l=j+1, h=n-1;
                while(l < h){
                    if(l>j+1 and nums[l]==nums[l-1]){
                        ++l;
                        continue;
                    }
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[h];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                        ++l;
                        --h;
                    }
                    else if(sum < target)
                        ++l;
                    else
                        --h;
                }
            }
        }
        return ans;
    }
};
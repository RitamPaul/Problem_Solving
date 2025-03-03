class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n);
        int low=0, high=n-1, freq=0;
        for(auto i=0,j=n-1; (i<n && j>=0); i++, j--){
            if(nums[i] < pivot)
                ans[low++] = nums[i];
            else if(nums[i] == pivot)
                freq++;
            if(nums[j] > pivot)
                ans[high--] = nums[j];
        }
        for(int i=1; i<=freq; i++)
            ans[low++] = pivot;
        return ans;
    }
};
class Solution {
public:
    int search(vector<int> &nums, int start, int end, int target){
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target < nums[mid]){
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i, x, y;
        for(i=n-2; i>=0; --i){
            if(nums[i] < nums[i+1])         break;
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        x = i;
        y = search(nums, x+1, n-1, nums[x]);
        swap(nums[x], nums[y]);
        reverse(nums.begin()+x+1, nums.end());
    }
};
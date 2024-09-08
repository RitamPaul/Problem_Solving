class Solution {
public:
    // checking cut count <= k or not
    bool safe(vector<int> &nums, int k, int target){
        int cutcount = 0, sum = 0;
        for(const auto &i : nums){
            sum += i;
            if(sum > target){
                ++cutcount;
                sum = i;
            }
            if(cutcount>k or i>target)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0], high=0, mid, ans=-1;

        for(const auto &i : nums)
            high += i;
        
        if(k == 1)
            return high;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(safe(nums, k-1, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
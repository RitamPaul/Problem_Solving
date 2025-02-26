class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int curmax=0, maxi=INT_MIN;
        for(const auto &i : nums){
            curmax += i;
            maxi = max(maxi, curmax);
            if(curmax < 0)
                curmax = 0;
        }
        int curmin=0, mini=INT_MAX;
        for(const auto &i : nums){
            curmin += i;
            mini = min(mini, curmin);
            if(curmin > 0)
                curmin = 0;
        }
        return max(abs(maxi), abs(mini));
    }
};
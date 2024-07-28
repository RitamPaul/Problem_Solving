class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), i=0, j=1;
        while(j < n){
            if((nums[i]!=nums[j]) or ((nums[i]==nums[j] and ((i>0 and nums[i-1]!=nums[i]) or (i==0))))){
                ++i;
                nums[i] = nums[j];
            }
            ++j;
        }
        return i+1;
    }
};
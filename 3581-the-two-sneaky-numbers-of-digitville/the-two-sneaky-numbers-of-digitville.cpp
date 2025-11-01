class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        int actualN = n-2;
        int apSum = actualN * (actualN-1) / 2;
        int givenSum = accumulate(nums.begin(), nums.end(), 0);

        for(auto &i : nums)
            ++i;
        
        int slowInd=0, fastInd=0;
        do{
            slowInd = nums[slowInd];
            fastInd = nums[nums[fastInd]];
        }while(slowInd != fastInd);
        slowInd=0;
        while(nums[slowInd] != nums[fastInd]){
            slowInd = nums[slowInd];
            fastInd = nums[fastInd];
        }
        
        int firstAns = nums[slowInd] - 1;
        // firstAns + (?) + apSum = givenSum
        int secondAns = givenSum - firstAns - apSum;
        return {firstAns, secondAns};
    }
};
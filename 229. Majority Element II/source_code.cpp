class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // using Boyer-Moore's Majority Voting Algorithm
        int n = nums.size();
        int num1, num2, count1=0, count2=0;
        for(int i=0; i<n; ++i){
            if(num1 == nums[i])
                ++count1;
            else if(num2 == nums[i])
                ++count2;
            else if(count1 == 0){
                count1 = 1;
                num1 = nums[i];
            }
            else if(count2 == 0){
                count2 = 1;
                num2 = nums[i];
            }
            else{
                --count1;
                --count2;
            }
        }
        count1 = count2 = 0;
        for(auto &i : nums){
            if(i == num1)
                ++count1;
            else if(i == num2)
                ++count2;
        }
        vector<int> ans;
        if(count1 > n/3)        ans.push_back(num1);
        if(count2 > n/3)        ans.push_back(num2);
        return ans;
    }
};
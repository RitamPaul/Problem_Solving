class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul{1}, countz{0};
        for(const auto &i : nums){
            if(i != 0)
                mul *= i;
            else
                ++countz;
        }
        
        for(auto &i : nums){
            if(i != 0){
                if(countz > 0)
                    i = 0;
                else
                    i = mul / i;
            }
            // integer is 0
            else{
                if(countz > 1)
                    i = 0;
                else
                    i = mul;
            }
        }
        
        return nums;
    }
};
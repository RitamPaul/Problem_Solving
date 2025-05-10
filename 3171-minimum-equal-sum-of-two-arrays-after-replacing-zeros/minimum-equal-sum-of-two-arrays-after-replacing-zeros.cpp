class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0, sum2=0, cnt1=0, cnt2=0;
        for(auto &i : nums1){
            if(i==0){
                ++cnt1;
                sum1+=1;
            }
            else
                sum1+=i;
        }
        for(auto &i : nums2){
            if(i==0){
                ++cnt2;
                sum2+=1;
            }
            else
                sum2+=i;
        }
        if((cnt1==0 and sum1<sum2) or (cnt2==0 and sum2<sum1))
            return -1;
        return max(sum1, sum2);
    }
};
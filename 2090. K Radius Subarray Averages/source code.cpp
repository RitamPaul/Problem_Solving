class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        unsigned long long int sum=0, start = 2*k, window = k+k+1;

        vector<int> ans(n, -1);

        if(k == 0)    return nums;
        if(k > n/2)    return ans;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(i >= start){
                ans[i-k] = sum / window;
                sum = sum - nums[i-window+1];
            }
        }

        return ans;
    }
};
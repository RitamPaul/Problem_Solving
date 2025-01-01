class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        // for(auto &i : nums)
        //     printf("%d ",i);
        // cout<<endl;
        int dif=INT_MAX, ans=0, ansl, ansm, ansr;
        for(int i=0; i<n-2; ++i){
            int l=i+1, h=n-1;
            int curtarget = target - nums[i];
            while(l < h){
                int sum = nums[i]+nums[l]+nums[h];
                int curdif = abs(target - sum);
                if(curdif < dif){
                    dif = curdif;
                    ans = sum;
                    ansl = nums[i];
                    ansm = nums[l];
                    ansr = nums[h];
                }
                if(nums[l]+nums[h] == curtarget){
                    ++l;
                    --h;
                }
                else if(nums[l]+nums[h] < curtarget)
                    ++l;
                else
                    --h;
            }
        }
        // printf("(%d, %d, %d)", ansl, ansm, ansr);
        return ans;
    }
};
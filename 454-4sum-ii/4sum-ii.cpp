class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        int n=nums1.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int l=0, h=n-1;
                while(l < n and h >= 0){
                    long long sum = (long long)nums1[i] + nums2[j] + nums3[l] + nums4[h];
                    if(sum == 0){
                        int count1=1, count2=1;
                        while(++l<n and nums3[l]==nums3[l-1])   ++count1;
                        while(--h>=0 and nums4[h]==nums4[h+1])   ++count2;
                        ans += (count1 * count2);
                    }
                    else if(sum < 0)
                        ++l;
                    else
                        --h;
                }
            }
        }
        return ans;
    }
};
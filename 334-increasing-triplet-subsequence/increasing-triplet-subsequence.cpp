class Solution {
public:
    int search(int target, vector<int> &arr){
        int n=arr.size(), l=0, r=n-1, m, ans;
        if(target < arr[0])
            return 0;
        if(target > arr.back())
            return arr.size();
        while(l <= r){
            m = l + (r - l) / 2;
            if(arr[m] >= target){
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        
        // maximum size is 2
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            if(arr.empty())
                arr.push_back(nums[i]);
            int ind = search(nums[i], arr);
            if(ind == arr.size()){
                if(arr.size() == 2){
                    printf("(%d, %d, %d)", arr[0], arr[1], nums[i]);
                    return true;
                }
                arr.push_back(nums[i]);
                continue;
            }
            arr[ind] = nums[i];
        }
        return false;
    }
};
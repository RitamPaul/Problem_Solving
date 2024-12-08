class Solution {
public:
    int ans, local;
    void mergesort(vector<int> &arr, int start, int end){
        if(start >= end)
            return;
        
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        
        vector<int> left = vector<int>(arr.begin()+start, arr.begin()+mid+1);
        vector<int> right = vector<int>(arr.begin()+mid+1, arr.begin()+end+1);
        
        int i=0, j=0, k=0;
        while(i<left.size() and j<right.size()){
            if(left[i] <= right[j])
                arr[start + k++] = left[i++];
            else{
                arr[start + k++] = right[j++];
                ans += (left.size() - i);
            }
        }
        while(i < left.size())
            arr[start + k++] = left[i++];
        while(j < right.size())
            arr[start + k++] = right[j++];
        return;
    }
    bool isIdealPermutation(vector<int>& nums) {
        ans = local = 0;
        int n=nums.size();
        for(int i=0; i<n-1; ++i){
            if(nums[i] > nums[i+1])
                ++local;
        }
        mergesort(nums, 0, n-1);
        return ans==local;
    }
};
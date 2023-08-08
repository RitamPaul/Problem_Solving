class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            //finds the target
            if(nums[mid]==target)
                return mid;
            //(left is sorted and target is in left) || (right is sorted and target is not in right)
            else if(    (nums[low]<nums[mid] && nums[low]<=target && target<nums[mid])
                    || (nums[mid]<nums[high] && !(nums[mid]<target && target<=nums[high]))   )
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};
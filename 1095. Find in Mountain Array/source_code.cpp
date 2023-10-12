/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int leftbs(MountainArray &arr, int start, int end, int &target){
        int low = 0, high = end, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr.get(mid) == target)
                return mid;
            else if(arr.get(mid) < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int rightbs(MountainArray &arr, int start, int end, int &target){
        int low = 0, high = end, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr.get(mid) == target)
                return mid;
            else if(arr.get(mid) < target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length(), low = 1, high = n - 2, highest;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int left = arr.get(mid - 1);
            int center = arr.get(mid);
            int right = arr.get(mid + 1);
            // peak found immediately
            if(left < center and center > right){
                highest = mid;
                break;
            }
            // found in increasing peak
            else if(left < center and center < right)
                low = mid + 1;
            else
                high = mid - 1;
        }
        int leftsearch = leftbs(arr, 0, highest, target);
        int rightsearch = rightbs(arr, highest+1, n-1, target);
        if(leftsearch != -1 and rightsearch != -1)
            return min(leftsearch, rightsearch);
        return max(leftsearch, rightsearch);
    }
};
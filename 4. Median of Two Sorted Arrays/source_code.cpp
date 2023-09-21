class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      // The whole Logic will work considering 1st Array size < 2nd Array size
      int n1 = nums1.size(), n2 = nums2.size();
      if(n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

      int l1, l2, r1, r2;
      int low = 0, high = n1;
      while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = ((n1 + n2 + 1) / 2) - mid1;
        l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
        if(mid1 - 1 >= 0)    l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0)    l2 = nums2[mid2 - 1];
        if(mid1 < n1)        r1 = nums1[mid1];
        if(mid2 < n2)        r2 = nums2[mid2];

        // case1 = answer found
        if(l1 <= r2 and l2 <= r1){
          // total count is EVEN
          if((n1 + n2) % 2 == 0){
            cout << "(" << max(l1, l2) << "," << min(r1, r2) << ")";
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
          }
          // total count is ODD
          else{
            cout << max(l1, l2);
            return (double)max(l1, l2);
          }
        }
        // case2 = answer will be from the left half
        if(l1 > r2)
          high = mid1 - 1;
        // case3 = answer will be from the right half
        else
          low = mid1 + 1;
      }
      return -1;
    }
};
class Solution {
public:
    int find1(int target, vector<int> &pre){
      int low = 0, high = pre.size()-1;
      while(low <= high){
        int mid = low + (high - low) / 2;
        if(pre[mid] == target)
          return mid;
        else if(target > pre[mid])
          low = mid + 1;
        else
          high = mid - 1;
      }
      return -1;
    }
    int find2(int target, vector<int> &suf){
      int low = 0, high = suf.size()-1;
      while(low <= high){
        int mid = low + (high - low) / 2;
        if(suf[mid] == target)
          return mid;
        else if(target > suf[mid])
          high = mid - 1;
        else
          low = mid + 1;
      }
      return -1;
    }
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();
      vector<int> pre(n), suf(n);
      pre[0] = nums[0];
      suf[n-1] = nums[n-1];

      for(int i=1; i<n; ++i)
        pre[i] = pre[i-1] + nums[i];
      for(int i=n-2; i>=0; --i)
        suf[i] = suf[i+1] + nums[i];

      int ans = INT_MAX;
      for(int i=n-1; i>=0; --i){
        if(suf[i] > x)
          break;
        int count = n - i;
        if(x - suf[i] == 0)
          ans = min(ans, count);
        else{
          int ind = find1(x-suf[i], pre);
          if(ind != -1 and ind < i){
            count += (ind + 1);
            ans = min(ans, count);
          }
        }
      }

      for(int i=0; i<n; ++i){
        if(pre[i] > x)
          break;
        int count = i + 1;
        if(x - pre[i] == 0)
          ans = min(ans, count);
        else{
          int ind = find2(x-suf[i], pre);
          if(ind != -1 and ind > i){
            count += (n - ind);
            ans = min(ans, count);
          }
        }
      }

      if(ans != INT_MAX)
        return ans;
      return -1;
    }
};
class Solution {
public:
    int n;
    bool helper(int val, vector<int> &candy, long long k){
        int ind=0, rem=candy[ind];
        while(k>0){
            if(ind >= n or rem < val)
                return false;
            k -= (rem / val);
            rem = rem % val;
            if(rem < val){
                ++ind;
                if(ind < n)   rem = candy[ind];
            }
        }
        return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        n = candies.size();
        sort(candies.begin(), candies.end(), greater<int>());
        int low = 1, high = candies.front(), mid, ans=0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(helper(mid, candies, k) == true){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
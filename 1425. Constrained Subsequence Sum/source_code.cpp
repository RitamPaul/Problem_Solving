class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> dp(n);
        for(int j = 0; j < n; ++j){
            int maxi = 0;
            while(pq.size() and j - pq.top().second > k)
                pq.pop();
            if(pq.size())
                maxi = max(maxi, pq.top().first);
            dp[j] = nums[j] + maxi;
            pq.push({dp[j], j});
        }
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i=0, j;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(j=0; j<k; ++j)
            pq.push({nums[j], j});
        ans.push_back(pq.top().first);
        while(j < n){
            ++i;
            // remove from priority queue
            while(pq.size() and pq.top().second < i)
                pq.pop();
            pq.push({nums[j], j});
            ans.push_back(pq.top().first);
            ++j;
        }
        return ans;
    }
};
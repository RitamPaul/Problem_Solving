class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Using priority Queue
        priority_queue<int>pq;
        for(int &i:nums){
            pq.push(i);
        }
        int res=0;
        while(k--){
            res=pq.top();
            pq.pop();
        }
        return res;
    }
};
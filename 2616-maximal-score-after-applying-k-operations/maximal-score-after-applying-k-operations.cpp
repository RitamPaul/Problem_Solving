class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(const auto &i : nums)
            pq.push(i);
        long long ans=0;
        while(k--){
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push( ceil((double)top / 3) );
        }
        return ans;
    }
};
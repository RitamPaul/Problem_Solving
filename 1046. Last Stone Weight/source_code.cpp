class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)  return stones[0];
        priority_queue<int> pq;
        for(auto i:stones)
            pq.push(i);
        while(pq.size()>1){
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            pq.push(max1-max2);
        }
        return pq.top();
    }
};
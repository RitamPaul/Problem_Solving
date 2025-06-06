class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        priority_queue<int> pq;
        for(auto &v : matrix){
            for(auto &i : v){
                pq.push(i);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
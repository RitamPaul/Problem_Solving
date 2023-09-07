class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
        int mod = 100000;
        vector<int> vis(mod, -1);
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while(q.size()){
            int count = q.size();
            while(count--){
                int front = q.front();
                q.pop();
                for(auto &i : arr){
                    int newstart = (front * i) % mod;
                    // end found immediately
                    if(newstart == end)
                        return vis[front]+1;
                    // newstart is not visited
                    if(vis[newstart] == -1){
                        q.push(newstart);
                        vis[newstart] = vis[front] + 1;
                    }
                }
            }
        }
        return -1;
    }
};
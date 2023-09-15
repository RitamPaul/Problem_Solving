class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& point) {
        // Using Prim's Algorithm
        int v = point.size(), count = -1, ans = 0, dis, ver;
        if(v == 1)
          return 0;
        vector<bool> vis(v, false);
        //min heap of <edge_weight,vertex>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(count < v-1){
          dis = pq.top().first;
          ver = pq.top().second;
          pq.pop();
          if(!vis[ver]){
            vis[ver] = true;
            ans += dis;
            ++count;
            cout<<"("<<dis<<","<<ver<<")";
            // for all vertex from the current vertex
            for(int i = 0; i<v; ++i){
              if(!vis[i]){
                dis = abs(point[ver][0] - point[i][0]) + abs(point[ver][1] - point[i][1]);
                pq.push({dis, i});
              }
            }
          }
        }
        return ans;
    }
};
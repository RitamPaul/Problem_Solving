//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int mini[(int)1e6+1];
  public:
    void dijkstra(int s, unordered_map<int, vector<vector<int>>> graph, unordered_map<int,int> &mp){
        
        pq.push({0,s});
        
        while(pq.size()){
            int cur = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            for(auto &v : graph[cur]){
                int neigh = v[0];
                int neigh_weight = v[1];
                if(weight + neigh_weight < mini[neigh]){
                    mini[neigh] = weight + neigh_weight;
                    pq.push({mini[neigh], neigh});
                    
                    mp[neigh] = cur;
                }
            }
        }
        
    }
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        for(int i=0; i<=n; ++i)      mini[i] = INT_MAX;
        mini[1] = 0;
        
        unordered_map<int,int> mp;
        
        unordered_map<int, vector<vector<int>>> graph;
        
        for(const auto &v : edges){
            int s = v[0];
            int d = v[1];
            int w = v[2];
            graph[s].push_back({d,w});
            graph[d].push_back({s,w});
        }
        
        dijkstra(1, graph, mp);
        
        if(mini[n] == INT_MAX)
            return {-1};
        
        vector<int> ans;
        
        ans.push_back(mini[n]);
        ans.push_back(n);
        
        int cur_node = n;
        bool flow = true;
        while(flow){
            int cur_par = mp[cur_node];
            ans.push_back(cur_par);
            cur_node = cur_par;
            if(cur_par == 1)
                flow = false;
        }
        reverse(ans.begin()+1, ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
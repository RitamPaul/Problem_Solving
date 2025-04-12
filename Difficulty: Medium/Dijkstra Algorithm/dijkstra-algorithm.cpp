//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> shortest(V,INT_MAX);
        shortest[src]=0;
        // default max heap but will use as min heap
        priority_queue<pair<int,int>> pq;
        pq.push({0,src});
        while(pq.size()){
            auto p=pq.top();
            pq.pop();
            int curweight=-1*p.first;
            int curnode=p.second;
            for(auto &neighpair : adj[curnode]){
                int neighnode=neighpair.first;
                int neighweight=neighpair.second;
                if(curweight+neighweight < shortest[neighnode]){
                    shortest[neighnode]=curweight+neighweight;
                    pq.push({-1*(curweight+neighweight),neighnode});
                }
            }
        }
        return shortest;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
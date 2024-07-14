//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        bool vis[v];
        memset(vis, 0, sizeof(vis));
        
        queue<pair<int,int>> q;
        for(int i=0; i<v; ++i){
            if(!vis[i]){
                // consider every i as starting vertex
                q.push({i, -1});
                vis[i] = true;
                while(q.size()){
                    int count = q.size();
                    while(count--){
                        int node = q.front().first;
                        int par = q.front().second;
                        q.pop();
                        
                        for(const auto &neigh : adj[node]){
                            if(neigh != par and vis[neigh])
                                return true;
                            else if(neigh != par){
                                vis[neigh] = true;
                                q.push({neigh, node});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
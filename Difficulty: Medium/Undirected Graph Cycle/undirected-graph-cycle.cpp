//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int parent, int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node]=true;
        for(auto &neigh : adj[node]){
            // cycle detected immediately
            if(neigh!=parent and vis[neigh]==true)
                return true;
            else if(neigh!=parent and !vis[neigh]){
                bool child=dfs(node, neigh, adj, vis);
                // cycle detected in path of this child
                if(child==true)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> vis(V+1,false);
        vector<vector<int>> adj(V+1, vector<int>());
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                bool ans=dfs(-1,i,adj,vis);
                if(ans==true)
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
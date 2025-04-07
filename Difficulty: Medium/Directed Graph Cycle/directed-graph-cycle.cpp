//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &cycle){
        vis[node]=true;
        bool ans=false;
        for(auto &neigh : adj[node]){
            if(vis[neigh] and cycle[neigh]==-1)
                return true;
            if(!vis[neigh]){
                ans=dfs(neigh,adj,vis,cycle);
                if(ans)
                    break;
            }
        }
        cycle[node]=ans;
        return ans;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> vis(V,false);
        vector<int> cycle(V,-1);
        vector<vector<int>> adj(V);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                bool ans=dfs(i,adj,vis,cycle);
                if(ans)
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
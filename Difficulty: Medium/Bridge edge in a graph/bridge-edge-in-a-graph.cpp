//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int source, destination;
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node]=true;
        if(node == this->destination)
            return true;
        bool destinationReached=false;
        for(auto &neigh : adj[node]){
            if(!vis[neigh]){
                destinationReached = dfs(neigh, adj, vis);
                if(destinationReached)
                    break;
            }
        }
        return destinationReached;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            // erasing edge between c and d
            if((e[0]==c and e[1]==d) or (e[0]==d and e[1]==c))
                continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        this->source=c;
        this->destination=d;
        vector<bool> vis(V, false);
        int cToDPossible = dfs(this->source, adj, vis);
        if(cToDPossible)
            return false;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
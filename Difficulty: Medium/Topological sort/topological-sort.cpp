//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        vector<int> incoming(V+1, 0);
        vector<vector<int>> adj(V+1, vector<int>());
        for(auto &e : edges){
            ++incoming[e[1]];
            adj[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for(int i=0; i<V; ++i){
            if(incoming[i]==0)
                q.push(i);
        }
        while(q.size()){
            int count=q.size();
            while(count--){
                int front=q.front();
                q.pop();
                ans.push_back(front);
                for(auto &neigh : adj[front]){
                    --incoming[neigh];
                    if(incoming[neigh]==0)
                        q.push(neigh);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
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
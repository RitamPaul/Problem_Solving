//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> shortest(V, (int)1e8);
        shortest[src]=0;
        int n=edges.size();
        for(int count=1; count<V; ++count){
            for(auto &e : edges){
                int u=e[0], v=e[1], w=e[2];
                if(shortest[u]!=(int)1e8 and shortest[u]+w<shortest[v])
                    shortest[v]=shortest[u]+w;
            }
        }
        for(auto &e : edges){
            int u=e[0], v=e[1], w=e[2];
            if(shortest[u]!=(int)1e8 and shortest[u]+w<shortest[v])
                return {-1};
        }
        return shortest;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


bool vis[1000+1];
class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        vector<int> dist(v, INT_MAX);
        memset(vis, false, sizeof vis);

        priority_queue<
            pair<int, int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({ dist[src], src });

        while (pq.size()) {
            int curnode = pq.top().second;
            int curdist = pq.top().first;
            pq.pop();
            vis[curnode] = true;

            for (const auto &neigh : adj[curnode]) {
                int neinode = neigh[0];
                int neidist = neigh[1];

                if (curdist + neidist < dist[neinode]) {
                    dist[neinode] =  curdist + neidist;
                    pq.push({ dist[neinode], neinode });
                }
            }
        }

        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
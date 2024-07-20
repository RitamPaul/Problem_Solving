//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


bool vis[1000+1];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int S)
    {
        // Code here
        memset(vis, 0, sizeof vis);
        vector<int> ans(v, INT_MAX);
        ans[S] = 0;
        pq.push( {0, S} );
        while(pq.size()){
            int curnode = pq.top().second;
            int curdist = pq.top().first;
            pq.pop();
            vis[curnode] = true;
            
            for(const auto &p : adj[curnode]){
                int neigh = p[0];
                int weigh = p[1];
                
                if(!vis[neigh] and curdist+weigh < ans[neigh]){
                    ans[neigh] = curdist + weigh;
                    pq.push( {ans[neigh], neigh} );
                }
            }
        }
        return ans;
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
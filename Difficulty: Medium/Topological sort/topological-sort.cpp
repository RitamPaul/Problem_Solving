//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    
	    int degree[v];
	    memset(degree, 0, sizeof(degree));
	    
	    for(int node=0; node<v; ++node){
	        for(const auto &child : adj[node]){
	            ++degree[child];
	        }
	    }
	    
	    for(int i=0; i<v; ++i){
	        if(degree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(q.size()){
	        int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(const auto &child : adj[front]){
                if(degree[child] > 0){
                    --degree[child];
                    if(degree[child] == 0)
                        q.push(child);
                }
            }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
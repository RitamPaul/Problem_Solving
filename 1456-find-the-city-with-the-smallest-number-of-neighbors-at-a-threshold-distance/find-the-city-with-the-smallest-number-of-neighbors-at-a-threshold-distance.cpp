class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>> adj(n, vector<int>(n, (int)1e9));
        for(int i=0; i<n; ++i)
            adj[i][i]=0;
        for(auto &e : edges){
            int u=e[0], v=e[1], w=e[2];
            adj[u][v]=w;
            adj[v][u]=w;
        }
        for(int k=0; k<n; ++k){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(adj[i][k]!=(int)1e9 and adj[k][j]!=(int)1e9)
                        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        int count=0, index=INT_MAX, indexcount=INT_MAX;
        for(int i=0; i<n; ++i){
            count=0;
            for(int j=0; j<n; ++j){
                if(i!=j and adj[i][j]<=thres)
                    ++count;
            }
            if(count <= indexcount){
                index = i;
                indexcount = count;
            }
        }
        return index;
    }
};
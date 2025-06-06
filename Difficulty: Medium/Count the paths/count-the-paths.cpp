class Solution {
  public:
    int f(int cur, int des, vector<vector<int>> &adj, vector<int> &dp){
        // base case
        if(cur==des)
            return 1;
        if(adj[cur].empty())
            return 0;
            
        // dp found case
        if(dp[cur]!=-1)
            return dp[cur];
        
        // recursive cases
        int sum=0;
        for(auto &i : adj[cur]){
            sum = sum + f(i, des, adj, dp);
        }
        
        // return from current state
        return dp[cur]=sum;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<int> dp(V+1, -1);
        vector<vector<int>> adj(V);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]);
        return f(src, dest, adj, dp);
    }
};
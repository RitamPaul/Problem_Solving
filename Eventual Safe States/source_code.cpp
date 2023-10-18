// User function Template for C++

class Solution {
  public:
    bool helper(int cur, vector<int> adj[], vector<bool> &vis, vector<int> &dp){
        // base case
        if(adj[cur].empty())
            return dp[cur] = true;
        
        if(dp[cur] != -1)
            return dp[cur];
        
        // recursive case
        bool possible = true;
        // checking every outgoing paths for current vertex
        for(auto &vertex : adj[cur]){
            // already repeating
            if(vis[vertex] == true){
                if(dp[vertex] == -1)
                    possible = possible & false;
                else
                    possible = possible & dp[vertex];
            }
            else{
                vis[vertex] = true;
                possible = possible & helper(vertex, adj, vis, dp);
            }
        }
        return dp[cur] = possible;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, false);
        vector<int> dp(V, -1), ans;
        for(int i = 0; i < V; ++i){
            if(!vis[i]){
                bool possible = helper(i, adj, vis, dp);
                if(possible)    ans.push_back(i);
            }
            else{
                if(dp[i])       ans.push_back(i);
            }
        }
        return ans;
    }
};
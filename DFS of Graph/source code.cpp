class Solution {
  public:
    void dfs(vector<int> adj[], vector<int> &ans, int ind, unordered_map<int,bool> &mp){
        ans.push_back(ind);
        mp[ind] = true;
        for(auto v:adj[ind]){
            if(mp[v]==false)
                dfs(adj, ans, v, mp);
        }
        return;
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool> mp;
        vector<int> ans;
        dfs(adj, ans, 0, mp);
        return ans;
    }
};
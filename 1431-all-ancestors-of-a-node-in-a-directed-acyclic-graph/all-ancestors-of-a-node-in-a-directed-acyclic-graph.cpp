class Solution {
public:
    set<int> dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<set<int>> &tempAns){
        if(vis[node])
            return tempAns[node];
        vis[node]=true;
        set<int> temp;
        for(auto &neigh : adj[node]){
            set<int> child=dfs(neigh, vis, adj, tempAns);
            child.insert(neigh);
            for(auto &i : child)
                temp.insert(i);
        }
        return tempAns[node]=temp;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<set<int>> tempAns(n);
        vector<vector<int>> adj(n);
        for(auto &e : edges)
            adj[e[1]].push_back(e[0]);
        for(int i=0; i<n; ++i){
            if(!vis[i])
                auto dummy=dfs(i,vis,adj,tempAns);
        }
        vector<vector<int>> ans;
        for(auto &st : tempAns){
            vector<int> temp(st.begin(), st.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
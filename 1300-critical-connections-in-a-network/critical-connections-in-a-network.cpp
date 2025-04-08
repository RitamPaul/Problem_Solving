class Solution {
public:
    int globalIndex;
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visIndex,
    vector<int> &visFromOtherParentIndex, vector<vector<int>> &ans){
        if(visIndex[node])
            return visFromOtherParentIndex[node];
        
        visIndex[node]=visFromOtherParentIndex[node]=globalIndex;
        ++globalIndex;
        for(auto &neigh : adj[node]){
            if(neigh==parent)
                continue;
            // neigh not visited previously anytime
            if(!visIndex[neigh]){
                visFromOtherParentIndex[node]=
                min(visFromOtherParentIndex[node], dfs(neigh, node, adj, visIndex, visFromOtherParentIndex, ans));
                // remove the edge node---neigh
                if(visIndex[node] < visFromOtherParentIndex[neigh])
                    ans.push_back({node,neigh});
            }
            // neigh is visited
            else{
                visFromOtherParentIndex[node]=
                min(visFromOtherParentIndex[node], visFromOtherParentIndex[neigh]);
            }
        }
        return visFromOtherParentIndex[node];
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this->globalIndex=1;
        vector<int> visIndex(n, 0);
        vector<int> visFromOtherParentIndex(n, 0);
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int dummy=dfs(0, -1, adj, visIndex, visFromOtherParentIndex, ans);
        return ans;
    }
};
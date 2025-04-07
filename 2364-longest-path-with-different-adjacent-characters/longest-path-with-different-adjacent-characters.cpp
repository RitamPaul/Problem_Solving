class Solution {
public:
    int v, ans;
    int dfs(int node, int parent, vector<vector<int>> &adj, string &s){
        // leaf
        if(adj[node].empty()){
            if(s[node]!=s[parent])
                return 1;
            return 0;
        }
        
        int childMax1=0, childMax2=0;
        for(auto &neigh : adj[node]){
            int child=dfs(neigh, node, adj, s);
            if(childMax1<child){
                childMax2=max(childMax2, childMax1);
                childMax1=child;
            }
            else if(childMax2<child)
                childMax2=child;            
        }
        this->ans=max(this->ans, childMax1+1+childMax2);
        if(parent==-1 or s[node]!=s[parent])
            return 1+max(childMax1,childMax2);
        return 0;
    }
    int longestPath(vector<int>& parent, string s) {
        this->v=parent.size();
        if(this->v==1)
            return 1;
        this->ans=INT_MIN;
        vector<vector<int>> adj(v);
        for(int i=1; i<v; ++i)
            adj[parent[i]].push_back(i);
        int dummy=dfs(0, -1, adj, s);
        return this->ans;
    }
};
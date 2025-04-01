class Solution {
public:
    int n;
    bool vis[(int)1e5+1];
    pair<bool,int> dfs(int node, vector<vector<int>> &adj, vector<bool>& hasApple){
        vis[node] = true;
        // base case

        // recursive case
        int childDist=0;
        for(auto &child : adj[node]){
            if(!vis[child]){
                auto dummy = dfs(child, adj, hasApple);
                bool appleFound = dummy.first;
                int distToApple = dummy.second;
                if(appleFound)
                    childDist += distToApple;
            }            
        }

        // return from current state
        // no apple in any child
        if(childDist==0){
            // current node has apple=>dist = 1 incoming + 1 returning
            if(hasApple[node])
                return {true, 1+1};
            return {false, 0};
        }
        // result dist = 1 incoming + all child + 1 returning
        return {true, 1+childDist+1};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->n = n;
        memset(vis, 0, sizeof vis);
        vector<vector<int>> adj(n+1, vector<int>());
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        auto ans = dfs(0, adj, hasApple);
        return ans.first ? ans.second-2 : 0;
    }
};
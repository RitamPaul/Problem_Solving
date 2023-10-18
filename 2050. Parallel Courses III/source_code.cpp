class Solution {
public:
    int helper(vector<int> &maxtofinish, vector<int> parent[], vector<bool> &vis, vector<int> &time, vector<int> &dp){
        // base case
        if(maxtofinish.empty())
            return 0;
        
        // recursive case
        int maxtime = 0;
        for(auto &i : maxtofinish){
            if(vis[i] == true and dp[i] != -1)
                maxtime = max(maxtime, dp[i]);
            else{
                vis[i] = true;
                dp[i] = time[i-1] + helper(parent[i], parent, vis, time, dp);
                maxtime = max(maxtime, dp[i]);
            }
        }
        return maxtime;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> parent[n+1];
        vector<bool> vis(n+1, false);
        vector<int> maxtofinish, dp(n+1, -1);

        for(auto &v : relations){
            parent[v[1]].push_back(v[0]);
            // v[0] has child v[1]
            vis[v[0]] = true;
        }

        for(int i = 1; i <= n; ++i){
            // vis[i] = false = has no child
            if(!vis[i])
                maxtofinish.push_back(i);
            // changing all, for fresh use of vis, in topo sort function
            vis[i] = false;
        }
        
        int ans = 0;
        for(auto &i : maxtofinish){
            vis[i] = true;
            ans = max(ans, time[i-1] + helper(parent[i], parent, vis, time, dp));
        }
        return ans;
    }
};
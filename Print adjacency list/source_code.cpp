class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> ans(V);
        for(auto &p:edges){
            ans[p.first].push_back(p.second);
            ans[p.second].push_back(p.first);
        }
        return ans;
    }
};
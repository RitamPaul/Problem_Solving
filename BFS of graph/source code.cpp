class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans, visit(V, false);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int front = q.front();
            if(visit[front] == false){
                ans.push_back(front);
                visit[front] = true;
            }
            q.pop();
            if(adj[front].size()){
                for(auto i:adj[front]){
                    if(visit[i] == false)
                        q.push(i);
                }
            }
        }
        return ans;
    }
};
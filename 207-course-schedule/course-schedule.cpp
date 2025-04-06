class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> incoming(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto &e : prerequisites){
            ++incoming[e[0]];
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(incoming[i]==0)
                q.push(i);
        }
        while(q.size()){
            int count=q.size();
            while(count--){
                int front=q.front();
                q.pop();
                for(auto &neigh : adj[front]){
                    --incoming[neigh];
                    if(incoming[neigh]==0)
                        q.push(neigh);
                }
            }
        }
        for(int i=0; i<numCourses; ++i){
            if(incoming[i]>0)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    int v;
    int dfs(int node, int id, vector<int>& edges, unordered_map<int,int> &index, unordered_map<int,int> &cycleLen){
        index[node]=id;
        cycleLen[node]=-1;
        // leaf node = no outgoing edge
        if(edges[node]==-1)
            return cycleLen[node]=0;
        
        // recursion
        int ans=0, child=edges[node];
        // not visited earlier
        if(!index[child])
            ans=max(ans, dfs(child, id+1, edges, index, cycleLen));
        // visited earlier
        else{
            // don't have cycleLen -> grandparent of curent node forming cycle now
            if(cycleLen[child]==-1){
                int cycleStartInd = index[child];
                int cycleEndInd = index[node];
                ans = max(ans, cycleEndInd-cycleStartInd+1);
            }
            // aready dfs -> have cycleLen -> no need to proceed more
            else
                ans = max(ans, cycleLen[child]);
        }

        // return from current state
        return cycleLen[node]=ans;
    }
    int longestCycle(vector<int>& edges) {
        this->v=edges.size();
        unordered_map<int,int> index, cycleLen;
        for(int i=0; i<this->v; ++i){
            if(!index[i]){
                int dummy=dfs(i,1,edges,index,cycleLen);
            }
        }
        
        int ans=0;
        for(auto &p : cycleLen)
            ans=max(ans, p.second);
        return ans==0 ? -1 : ans;
    }
};
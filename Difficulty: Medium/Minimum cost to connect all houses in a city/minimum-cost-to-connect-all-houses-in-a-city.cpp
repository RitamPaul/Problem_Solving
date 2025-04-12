//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int v=houses.size();
        vector<vector<int>> adj(v, vector<int>(v,-1));
        for(int i=0; i<v; ++i){
            for(int j=0; j<v; ++j){
                // distance not calculated
                if(adj[i][j]==-1){
                    int xi=houses[i][0];
                    int yi=houses[i][1];
                    int xj=houses[j][0];
                    int yj=houses[j][1];
                    int dis=abs(xi-xj)+abs(yi-yj);
                    adj[i][j]=adj[j][i]=dis;
                }
            }
        }
        vector<bool> vis(v,false);
        int ans=0;
        // default max heap but will use as min heap
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,-1}});
        while(pq.size()){
            auto p=pq.top();
            pq.pop();
            int curdis=-1*p.first;
            int curnode=p.second.first;
            int curparent=p.second.second;
            if(curparent!=-1 and !vis[curnode])
                ans+=curdis;
            if(vis[curnode])
                continue;
            vis[curnode]=true;
            for(int i=0; i<v; ++i){
                if(i!=curnode and !vis[i] and adj[curnode][i]!=-1){
                    pq.push({-1*adj[curnode][i], {i,curnode}});
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends
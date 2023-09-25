class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        map<pair<int,int>, bool> vis;
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<int> ans;
        vis[{0,0}] = true;
        pq.push( { A[0]+B[0], {0,0} } );
        while(K-- and pq.size()){
            ans.push_back(pq.top().first);
            int fa = pq.top().second.first;
            int fb = pq.top().second.second;
            pq.pop();
            if(fa+1 < N and vis[{ fa+1, fb }] == false){
                vis[{ fa+1, fb }] = true;
                pq.push({ A[fa+1]+B[fb], {fa+1,fb} });
            }
            if(fb+1 < N and vis[{ fa, fb+1 }] == false){
                vis[{ fa, fb+1 }] = true;
                pq.push({ A[fa]+B[fb+1], {fa,fb+1} });
            }
        }
        return ans;
    }
};
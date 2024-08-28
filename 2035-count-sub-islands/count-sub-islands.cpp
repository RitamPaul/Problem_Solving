class Solution {
public:
    void bfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1, vector<vector<bool>> &vis, int x, int y, int &ans){
        int n = grid2.size(), m = grid2[0].size();
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        vis[x][y] = true;
        bool same = true;
        queue<pair<int,int>> q;
        q.push({x,y});
        while(q.size()){
            int count = q.size();
            while(count--){
                int frontx = q.front().first;
                int fronty = q.front().second;
                q.pop();
                if(grid1[frontx][fronty] == 0)
                    same = false;
                // for all 4 directions
                for(int i=0; i<4; ++i){
                    if(0<=frontx+dx[i] and frontx+dx[i]<n and 0<=fronty+dy[i] and fronty+dy[i]<m
                    and !vis[frontx+dx[i]][fronty+dy[i]] and grid2[frontx+dx[i]][fronty+dy[i]]==1){
                        q.push({frontx+dx[i], fronty+dy[i]});
                        vis[frontx+dx[i]][fronty+dy[i]] = true;
                    }
                }
            }
        }
        if(same)
            ++ans;
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(), m=grid2[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int ans=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid2[i][j]==1 and !vis[i][j])
                    bfs(grid2, grid1, vis, i, j, ans);
            }
        }
        return ans;
    }
};
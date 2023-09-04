// User function Template for C++

class Solution{
public:
    void bfs(vector<vector<char>> &mat, vector<vector<bool>> &vis, int x, int y){
        int n = mat.size(), m = mat[0].size();
        vis[x][y] = true;
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        queue<pair<int,int>> q;
        q.push({x,y});
        while(q.size()){
            int count = q.size();
            while(count--){
                int frontx = q.front().first;
                int fronty = q.front().second;
                q.pop();
                // moving all 4 directions
                for(int i=0; i<4; ++i){
                    if(0<=frontx+dx[i] and frontx+dx[i]<n and 0<=fronty+dy[i] and fronty+dy[i]<m
                    and !vis[frontx+dx[i]][fronty+dy[i]] and mat[frontx+dx[i]][fronty+dy[i]]=='O'){
                        q.push({frontx+dx[i], fronty+dy[i]});
                        vis[frontx+dx[i]][fronty+dy[i]] = true;
                    }
                }
            }
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat){
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                // 1st row and last row
                if((i==0 or i==n-1) and mat[i][j]=='O' and !vis[i][j])
                    bfs(mat, vis, i, j);
                else if((j==0 or j==m-1) and mat[i][j]=='O' and !vis[i][j])
                    bfs(mat, vis, i, j);
            }
        }
        
        // for final answer
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!vis[i][j] and mat[i][j]=='O')
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};
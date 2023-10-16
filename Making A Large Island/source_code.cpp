//User function Template for C++

int n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
class Solution
{
public:
    int helper(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& vis, int &islandindex){
        int ans = 0, fx, fy, nx, ny;
        queue<pair<int,int>> q;
        q.push({row, col});
        while(q.size()){
            int count = q.size();
            while(count--){
                fx = q.front().first;
                fy = q.front().second;
                q.pop();
                grid[fx][fy] = islandindex;
                ans++;
                for(int i = 0; i<4; ++i){
                    nx = fx + dx[i];
                    ny = fy + dy[i];
                    if(0<=nx and nx<n and 0<=ny and ny<n and !vis[nx][ny] and grid[nx][ny]==1){
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid){
        n = grid.size();
        int islandindex = 10;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        unordered_map<int,int> index;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(!vis[i][j] and grid[i][j] == 1){
                    vis[i][j] = true;
                    int islandsize = helper(grid, i, j, vis, islandindex);
                    index[islandindex] = islandsize;
                    ++islandindex;
                }
            }
        }
        int ans = INT_MIN;
        int nx, ny;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                // 0 found and have to change
                if(grid[i][j] == 0){
                    unordered_map<int,bool> taken;
                    int maxislandpossible = 1;
                    // go for every direction and pick unique index islands
                    for(int k = 0; k<4; ++k){
                        nx = i + dx[k];
                        ny = j + dy[k];
                        if(0<=nx and nx<n and 0<=ny and ny<n and grid[nx][ny]>=10){
                            int curindex = grid[nx][ny];
                            if(taken[curindex] == false){
                                taken[curindex] = true;
                                maxislandpossible += index[curindex];
                            }
                        }
                    }
                    ans = max(ans, maxislandpossible);
                }
            }
        }
        return (ans !=  INT_MIN) ? ans : n*n;
    }
};
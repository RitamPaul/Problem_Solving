class Solution {
public:
    void func(vector<vector<int>>& land, vector<vector<int>>& vis, vector<vector<int>>& ans, int x, int y){
        vector<int> position;
        position.push_back(x);      position.push_back(y);
        int n=land.size(), m=land[0].size(), maxx=x, maxy=y;
        while(maxy+1<m and land[x][maxy+1]==1 and !vis[x][maxy+1])
            ++maxy;
        while(maxx+1<n and land[maxx+1][y]==1 and !vis[maxx+1][y])
            ++maxx;
        for(int i=x; i<=maxx; ++i){
            for(int j=y; j<=maxy; ++j)
                vis[i][j] = true;
        }
        position.push_back(maxx);   position.push_back(maxy);
        ans.push_back(position);
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(), m=land[0].size();
        vector<vector<int>> ans, vis(n, vector<int>(m,false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(land[i][j]==1 and !vis[i][j])
                    func(land, vis, ans, i, j);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        unordered_map<int,int> mp;
        int mark = 1;
        for(const auto &v : artifacts){
            for(int i=v[0]; i<=v[2]; ++i){
                for(int j=v[1]; j<=v[3]; ++j){
                    ++mp[mark];
                    mat[i][j] = mark;
                }
            }
            ++mark;
        }
        for(const auto &v : dig)
            --mp[mat[v[0]][v[1]]];
        
        int ans = 0;
        for(const auto &p : mp){
            if(p.second == 0)
                ++ans;
        }
        return ans;
    }
};
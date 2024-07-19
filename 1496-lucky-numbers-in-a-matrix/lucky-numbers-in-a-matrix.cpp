class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> minrow(m, INT_MAX);
        vector<int> maxcol(n, INT_MIN);

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                minrow[i] = min(minrow[i], mat[i][j]);
                maxcol[j] = max(maxcol[j], mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(minrow[i] == maxcol[j])
                    ans.push_back(minrow[i]);
            }
        }
        return ans;
    }
};
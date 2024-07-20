class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        for(auto &r : mat)
            reverse(r.begin(), r.end());
        
        for(int i=0; i<r; ++i){
            for(int j=0; j<c-i; ++j)
                swap(mat[i][j], mat[c-1-j][r-1-i]);
        }
    }
};
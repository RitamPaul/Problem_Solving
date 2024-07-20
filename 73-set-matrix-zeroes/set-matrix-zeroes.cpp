class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size();
        bool col0 = false;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(mat[i][j] == 0){
                    if(j==0){
                        col0 = true;
                        continue;
                    }
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // filling from 1,1 to right-bottom
        for(int i=1; i<r; ++i){
            for(int j=1; j<c; ++j){
                if(mat[i][0] == 0 or mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }

        // fill both 1st row, 1st col
        if(mat[0][0] == 0){
            // 1st row
            for(int j=0; j<c; ++j)
                mat[0][j] = 0;
        }

        // fill only 1st col
        if(col0){
            for(int i=0; i<r; ++i)
                mat[i][0] = 0;
        }
    }
};
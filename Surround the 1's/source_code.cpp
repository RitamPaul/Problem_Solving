class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int row=matrix.size(), col=matrix[0].size(), ans=0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                // matrix cell value = 1
                if(matrix[i][j]==1){
                    int count=0;
                    // up
                    if(i>0 and matrix[i-1][j]==0)
                        ++count;
                    // down
                    if(i<row-1 and matrix[i+1][j]==0)
                        ++count;
                    // left
                    if(j>0 and matrix[i][j-1]==0)
                        ++count;
                    // right
                    if(j<col-1 and matrix[i][j+1]==0)
                        ++count;
                    // left-up diagonal
                    if(i>0 and j>0 and matrix[i-1][j-1]==0)
                        ++count;
                    // right-up diagonal
                    if(i>0 and j<col-1 and matrix[i-1][j+1]==0)
                        ++count;
                    // left-down diagonal
                    if(i<row-1 and j>0 and matrix[i+1][j-1]==0)
                        ++count;
                    // right-down diagonal
                    if(i<row-1 and j<col-1 and matrix[i+1][j+1]==0)
                        ++count;
                    // final check for answer
                    if(count != 0 and count % 2 == 0)
                        ++ans;
                }
            }
        }
        return ans;
    }
};
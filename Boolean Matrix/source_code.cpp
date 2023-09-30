class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix){
        unordered_map<int,bool> row, col;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j]==1){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        // row change
        for(int i=0; i<n; ++i){
            if(row[i] == true){
                for(auto &item:matrix[i])
                    item = 1;
            }
        }
        
        // col change
        for(int j=0; j<m; ++j){
            if(col[j] == true){
                for(int i=0; i<n; ++i)
                    matrix[i][j] = 1;
            }
        }
        
        return;
    }
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m, 0));
        int ans=0, height, breadth;
        stack<int> stk;
        for(int i=0; i<n; ++i){
            // copying char into int
            for(int j=0; j<m; ++j)
                mat[i][j] = (matrix[i][j]=='1' ? 1 : 0);
            // addition from prev row of actual matrix
            for(int j=0; j<m; ++j){
                if(0<=i-1 and matrix[i][j]=='1')
                    mat[i][j] += mat[i-1][j];
            }
            // printf("(%d-", i);
            // for(auto &item : mat[i])
            //     printf("%d,", item);
            // printf(") ");
            
            // for all who have smaller item in its right
            for(int j=0; j<m; ++j){
                while(stk.size() and mat[i][j]<=mat[i][stk.top()]){
                    height = mat[i][stk.top()];
                    stk.pop();
                    if(stk.empty())
                        breadth = j;
                    else
                        breadth = j - stk.top() - 1;
                    
                    if(height <= breadth)
                        ans = max(ans, height*height);
                }
                stk.push(j);
            }
            // for all who haven't any smaller item in its right
            while(stk.size()){
                height = mat[i][stk.top()];
                stk.pop();
                if(stk.empty())
                    breadth = m;
                else
                    breadth = m - stk.top() - 1;
                
                if(height <= breadth)
                    ans = max(ans, height*height);
            }
            // printf("(%d-%d) ", i, ans);
        }
        
        return ans;
    }
};
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n){
        vector<int> rows(n), cols(n);
        int maxi = INT_MIN;
        // for row sum
        for(int row=0; row<n; ++row){
            int sum=0;
            for(int col=0; col<n; ++col)
                sum += matrix[row][col];
            rows[row] = sum;
            maxi = max(maxi, sum);
        }
        
        // for column sum
        for(int col=0; col<n; ++col){
            int sum=0;
            for(int row=0; row<n; ++row)
                sum += matrix[row][col];
            cols[col] = sum;
            maxi = max(maxi, sum);
        }
        
        // calculating the answer
        int ans=0;
        for(auto &item : rows)
            ans += abs(item - maxi);
        return ans;
    }
};
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int mat[MAX][MAX],int row,int col)
    {
        int num;
        unordered_map<int,bool> mp;
        vector<vector<int>> ans;
        vector<int> help(col);
        
        for(auto i=0; i<row; i++){
            num = 0;
            for(auto j=0; j<col; j++){
                help[j] = mat[i][j];
                num = (num*10) + mat[i][j];
            }
            if(!mp[num]){
                mp[num] = true;
                ans.push_back(help);
            }
        }
        
        return ans;
    }
};
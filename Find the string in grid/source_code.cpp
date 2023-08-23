// up, down, left, right, up-left, up-right, down-left, down-right
int x[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int y[] = { 0, 0, -1, 1, -1,  1, -1, 1};
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[0]==v2[0])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
class Solution {
public:
    bool valid(vector<vector<char>> &grid, string &word, int i, int j, int dir){
        int row=grid.size(), col=grid[0].size(), ind=1;
        while(i<row and i>=0 and j<col and j>=0 and ind<word.size()){
            if(grid[i][j] != word[ind])
                break;
            i += x[dir];
            j += y[dir];
            ++ind;
        }
        if(ind==word.size())
            return true;
        return false;
    }
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int row=grid.size(), col=grid[0].size();
	    vector<vector<int>> ans;
	    for(int i=0; i<row; ++i){
	        for(int j=0; j<col; ++j){
	            // 1st letter matches, check for entire
	            if(grid[i][j] == word[0]){
    	            for(int dir=0; dir<8; ++dir){
    	                if(valid(grid, word, i+x[dir], j+y[dir], dir)){
    	                    vector<int> temp = {i,j};
    	                    ans.push_back(temp);
    	                    break;
    	                }
    	            }
	            }
	        }
	    }
	    sort(ans.begin(), ans.end(), cmp);
	    return ans;
	}
};
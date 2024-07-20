class Solution {
public:
    int count;
    vector<vector<int>> generateMatrix(int n) {
        count = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int topr=0, downr=n-1, leftc=0, rightc=n-1;
        // each boundary
        while(topr <= downr and leftc <= rightc){
            for(int j=leftc; j<=rightc; ++j)
                ans[topr][j] = count++;
            ++topr;

            if(topr <= downr){
                for(int i=topr; i<=downr; ++i)
                    ans[i][rightc] = count++;
                --rightc;
            }
            if(topr <= downr and rightc >= leftc){
                for(int j=rightc; j>=leftc; --j)
                    ans[downr][j] = count++;
                --downr;
            }
            if(downr >= topr and leftc <= rightc){
                for(int i=downr; i>=topr; --i)
                    ans[i][leftc] = count++;
                ++leftc;
            }
        }

        return ans;
    }
};
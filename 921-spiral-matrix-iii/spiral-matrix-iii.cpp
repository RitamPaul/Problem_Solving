class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rstart, int cstart) {
        vector<vector<int>> ans;
        ans.push_back({rstart, cstart});
        int topr=rstart, downr=rstart, leftc=cstart, rightc=cstart+1;
        int p=2;
        // printf("(%d,%d-%d)", rstart, cstart, p);
        while(p <= r*c){
            // top row = l -> r
            for(int j=leftc+1; j<=rightc; ++j){
                if(0<=topr and topr<r and 0<=j and j<c){
                    ans.push_back( {topr, j} );
                    // printf("(%d,%d-%d)", topr, j, p);
                    p++;
                }
            }
            ++downr;
            
            // right col = u -> d
            for(int i=topr+1; i<=downr; ++i){
                if(0<=i and i<r and 0<=rightc and rightc<c){
                    ans.push_back( {i, rightc} );
                    // printf("(%d,%d-%d)", i, rightc, p);
                    p++;
                }
            }
            --leftc;

            // bottom row = r -> l
            for(int j=rightc-1; j>=leftc; --j){
                if(0<=downr and downr<r and 0<=j and j<c){
                    ans.push_back( {downr, j} );
                    // printf("(%d,%d-%d)", downr, j, p);
                    p++;
                }
            }
            --topr;

            // left col = d -> u
            for(int i=downr-1; i>=topr; --i){
                if(0<=i and i<r and 0<=leftc and leftc<c){
                    ans.push_back( {i, leftc} );
                    // printf("(%d,%d-%d)", i, leftc, p);
                    p++;
                }
            }
            ++rightc;
        }
        return ans;
    }
};
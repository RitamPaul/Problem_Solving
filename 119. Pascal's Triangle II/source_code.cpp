class Solution {
public:
    vector<int> getRow(int row) {
        int prev, temp;
        vector<int> ans(row + 1);
        ans[0] = 1;
        for(int i=1; i<=row; ++i){
            prev = 0;
            for(int j=0; j<=i; ++j){
                temp = ans[j];
                ans[j] = ans[j] + prev;
                prev = temp;
            }
        }
        return ans;
    }
};
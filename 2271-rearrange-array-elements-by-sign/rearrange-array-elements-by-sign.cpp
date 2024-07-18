class Solution {
public:
    vector<int> rearrangeArray(vector<int>& num) {
        vector<int> ans(num.size());
        int p=0, n=1;
        for(const auto &i : num){
            if(i > 0){
                ans[p] = i;
                p += 2;
            }
            else{
                ans[n] = i;
                n += 2;
            }
        }
        return ans;
    }
};
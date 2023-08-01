class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &temp, int &n, int k, int start){
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(auto i=start; i<=n; i++){
            temp.push_back(i);
            func(ans, temp, n, k-1, i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, temp, n, k, 1);
        return ans;
    }
};
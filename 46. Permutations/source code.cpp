class Solution {
public:
    void func(vector<int> &num, int ind, vector<vector<int>> &ans, vector<int> &temp){
        int n=num.size();
        if(ind>n){
            ans.push_back(temp);
            return;
        }

        for(auto i=0; i<n; i++){
            if(num[i] != INT_MAX){
                temp.push_back(num[i]);
                num[i] = INT_MAX;
                func(num, ind+1, ans, temp);
                num[i] = temp.back();
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(num, 1, ans, temp);
        return ans;
    }
};
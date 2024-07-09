class Solution {
public:
    void dfs(string &s, int n, vector<string> &ans){
        if(n <= 0){
            ans.push_back(s);
            return;
        }
        if(s.empty() or (s.back()=='1')){
            s.push_back('0');
            dfs(s, n-1, ans);
            s.pop_back();
        }
        s.push_back('1');
        dfs(s, n-1, ans);
        s.pop_back();

        return;
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        dfs(s, n, ans);
        return ans;
    }
};
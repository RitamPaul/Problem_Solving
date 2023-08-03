class Solution {
public:
    void func(string &digits, vector<vector<char>> &mp, int d, vector<string> &ans, string &s){
        if(d == digits.size()){
            ans.push_back(s);
            return;
        }

        for(auto &ch:mp[digits[d] - '0']){
            s.push_back(ch);
            func(digits, mp, d+1, ans, s);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s="";
        int d=digits.size();
        if(d == 0)        return ans;
        vector<vector<char>> mp(10);
        mp[2] = {'a','b','c'};      mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};      mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};      mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};      mp[9] = {'w','x','y','z'};
        func(digits, mp, 0, ans, s);
        return ans;
    }
};
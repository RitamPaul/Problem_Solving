class Solution {
public:
    bool func(string &s, unordered_map<string,bool> &mp, int start, vector<int> &dp){
        int n=s.size();
        if(start==n)
            return 1;
        
        if(dp[start] != -1)
            return dp[start];

        string temp="";
        for(auto i=start; i<n; i++){
            temp += s[i];
            if(mp[temp]==true && func(s, mp, i+1, dp)==1){
                dp[i] = 1;
                return dp[i];
            }
        }
        dp[start]=0;
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& dict) {
        unordered_map<string,bool> mp;
        vector<int> dp(s.size(), -1);
        for(auto &s:dict)
            mp[s] = true;
        
        return func(s, mp, 0, dp);
    }
};
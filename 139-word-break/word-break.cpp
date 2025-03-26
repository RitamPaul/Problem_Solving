class Solution {
public:
    int n;
    bool f(int ind, string &s, unordered_set<string> &st, vector<int> &dp) {
        // base case
        if(ind >= n)
            return true;
        
        // dp found case
        if(dp[ind] != -1)
            return dp[ind];
        
        // recursive case
        string temp="";
        bool ans = false;
        for(int cut=ind; cut<n; ++cut) {
            temp += s[cut];
            // this word found in dictionary
            if(st.count(temp)) {
                ans = f(cut+1, s, st, dp);
                // after taking this word, rem. string can be split into words
                if(ans)
                    break;
            }
        }
        
        // return from current state
        return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& dictionary) {
        n=s.size();
        unordered_set<string> st;
        for(auto &s : dictionary)
            st.insert(s);
        // dp vector
        vector<int> dp(n+1, -1);
        return f(0, s, st, dp);
    }
};
class Solution {
public:
    int n, i;
    string helper(string &s){
        string ans = "";
        for(; i<n and s[i]!=')'; ++i){
            if(s[i] == '('){
                ++i;
                string mid = helper(s);
                reverse(mid.begin(), mid.end());
                ans = ans + mid;
            }
            else
                ans += s[i];
        }
        return ans;
    }
    string reverseParentheses(string s) {
        n = s.size();
        i = 0;
        return helper(s);
    }
};
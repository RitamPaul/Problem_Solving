class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty())
                stk.push(s[i]);
            else{
                if(stk.top()=='(' and s[i]==')')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        return stk.size();
    }
};
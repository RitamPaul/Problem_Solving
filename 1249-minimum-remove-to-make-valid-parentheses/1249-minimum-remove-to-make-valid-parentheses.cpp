class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,char>> st;
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; ++i){
            if(s[i]=='(')
                st.push({i, '('});
            else if(s[i]==')'){
                if(st.size() and st.top().second == '(')
                    st.pop();
                else
                    st.push({i, ')'});
            }
        }
        for(int i=n-1; i>=0; --i){
            if(st.size() and st.top().first == i)
                st.pop();
            else
                ans += s[i];
        }
        reverse(ans.begin(),  ans.end());
        return ans;
    }
};
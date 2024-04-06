class Solution {
public:
    int minSwaps(string s) {
        stack<pair<int,char>> st;
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; ++i){
            if(s[i]=='[')
                st.push({i, '['});
            else if(s[i]==']'){
                if(st.size() and st.top().second == '[')
                    st.pop();
                else
                    st.push({i, ']'});
            }
        }
        int len = st.size() / 2;
        if(len % 2 == 0)
            return len / 2;
        else
            return len / 2 + 1;
    }
};
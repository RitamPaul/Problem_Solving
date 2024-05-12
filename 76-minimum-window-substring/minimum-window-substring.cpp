class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), i=0, j=0, mini=INT_MAX, start=-1, end=-1;
        unordered_map<char,int> st;
        unordered_map<char,int> valid, curw;
        for(auto &ch : t){
            ++valid[ch];
            ++st[ch];
        }
        while(j < n){
            // current char is valid
            if(valid.count(s[j])){
                ++curw[s[j]];
                if(st.count(s[j])){
                    --st[s[j]];
                    if(st[s[j]] == 0)
                        st.erase(s[j]);
                }
            }
            // all valid char collected
            if(st.empty()){
                // remove from left end to shorten
                while(i <= j){
                    // valid char encountered
                    if(valid.count(s[i])){
                        --curw[s[i]];
                        if(curw[s[i]] < valid[s[i]]){
                            ++st[s[i]];
                            if(j-i+1 < mini){
                                mini = j-i+1;
                                start = i;
                                end = j;
                            }
                            ++i;
                            break;
                        }
                    }
                    ++i;
                }
            }
            ++j;
        }
        if(mini == INT_MAX)     return "";
        string ans="";
        for(int i=start; i<=end; ++i)
            ans += s[i];
        return ans;
    }
};
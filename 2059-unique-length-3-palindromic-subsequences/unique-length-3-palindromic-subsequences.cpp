class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // const space
        vector<int> left(26, 0), right(26, 0);
        // for ans
        unordered_set<string> st;
        int n=s.size();
        for(int i=n-1; i>=0; --i)
            ++right[s[i]-'a'];
        // traversing given string
        for(int i=0; i<n; ++i){
            char cur=s[i];
            if(right[cur-'a'])
                --right[cur-'a'];
            // checking for all letters found in left and right
            for(int j=0; j<26; ++j){
                if(left[j] and right[j]){
                    string push = "";
                    push += char('a'+j);
                    push += cur;
                    push += char('a'+j);
                    st.insert(push);
                }
            }
            ++left[cur-'a'];
        }
        return st.size();
    }
};
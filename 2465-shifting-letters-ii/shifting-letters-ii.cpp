class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> prefix(n+1, 0);
        for(auto &q : shifts){
            int start=q[0];
            int end=q[1];
            int dir=q[2];
            // forward
            if(dir){
                ++prefix[start];
                --prefix[end+1];
            }
            // backward
            else{
                --prefix[start];
                ++prefix[end+1];
            }
        }
        // effective change
        prefix[0]%=26;
        for(int i=1; i<n+1; ++i)
            prefix[i]=(prefix[i]+prefix[i-1])%26;
        // calculating ans
        for(int i=0; i<n; ++i){
            int val=prefix[i];
            int cur=(s[i]-'a');
            if(val>=0)
                cur=(cur+val)%26;
            else
                cur=(cur+val+26)%26;
            s[i]='a'+cur;
        }
        return s;
    }
};
int lpsdp[(int)1e6 + 1];
class Solution {
public:
    string longestPrefix(string str) {
        int n = str.size();
        memset(lpsdp, 0, sizeof lpsdp);
        
        int pre=0, suf=1;
        while(suf < n){
            if(str[pre] == str[suf]){
                lpsdp[suf] = pre + 1;
                ++pre;
                ++suf;
            }
            else{
                if(pre == 0){
                    lpsdp[suf] = 0;
                    ++suf;
                }
                else
                    // pre = lpsdp[   lpsdp[suf-1]   ] - 1;
                    pre = lpsdp[pre-1];
            }
        }
        int len = lpsdp[n-1];
        string ans="";
        for(int i=0; i<len; ++i)
            ans += str[i];
        return ans;
    }
};
int dp[(int)(1e3+1)][(int)(1e3+1)][2];
int maxsize;
class Solution {
public:
    int f(int cursize, int prevcopysize, bool curcopy){
        // base case
        if(cursize == maxsize)
            return dp[cursize][prevcopysize][curcopy] = 0;
        if(maxsize < cursize)       return 1e8;

        int paste1=1e8, paste2=1e8, copy=1e8;

        // dp found case
        if(dp[cursize][prevcopysize][curcopy] != -1)
            return dp[cursize][prevcopysize][curcopy];

        // recursive case
        // cur=true=copy -> have to copy now
        if(curcopy){
            copy = 1 + f(cursize, cursize, false);
        }
        // cur=false=paste
        else{
            paste1 = 1 + f(cursize+prevcopysize, prevcopysize, false);
            paste2 = 1 + f(cursize+prevcopysize, prevcopysize, true);
        }

        // return from current state
        return dp[cursize][prevcopysize][curcopy] = min({paste1, paste2, copy});
    }
    int minSteps(int n) {
        if(n == 1)      return 0;
        maxsize = n;
        memset(dp, -1, sizeof(dp));
        return f(1,0,true);
    }
};
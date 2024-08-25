int dp[200+1][200+1][200+1];
int n1=0, n2=0, n3=0;
class Solution {
public:
    int f(string &s1, string &s2, string &s3, int i, int j, int k){
        // base case
        if(k>=n3)
            return true;

        // dp found case
        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        bool allocatetofirst=false, allocatetosecond=false;
        // recursive case
        if(i<n1 and s1[i] == s3[k])
            allocatetofirst = f(s1, s2, s3, i+1, j, k+1);
        if(j<n2 and s2[j] == s3[k])
            allocatetosecond = f(s1, s2, s3, i, j+1, k+1);

        // return from current state
        return dp[i][j][k] = allocatetofirst or allocatetosecond;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        if(n1+n2 != n3)
            return false;
        
        memset(dp, -1, sizeof dp);
        return f(s1, s2, s3, 0, 0, 0);
    }
};
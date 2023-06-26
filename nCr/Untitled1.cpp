class Solution{
public:
    int mod = 1000000007;
    int nCr(int n, int r){
        if(r==0 || r==n)    return 1;
        else if(r>n)    return 0;
        vector<int> help(n+1, 0);
        help[0] = 1;
        for(auto i=1; i<=n; i++){
            for(auto j=i; j>=1; j--){
                help[j] = (help[j] + help[j-1]) % mod;
            }
        }
        return help[r] % mod;
    }
};
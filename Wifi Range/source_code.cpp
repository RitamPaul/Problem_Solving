class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int c0=0, f1=false;
        for(int i=0; i<N; ++i){
            if(S[i]=='0')   c0++;
            else{
                if(f1==false && c0>X)   return 0;
                else if(f1==true && c0 > 2*X)   return 0;
                c0=0;
                f1=true;
            }
        }
        if(c0<=X && f1==true)    return 1;
        else    return 0;
    }
};
class Solution {
public:
    int minFlips(int a, int b, int c) {
        bool abit, bbit, cbit;
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            abit = a & 1;   a=a>>1;
            bbit = b & 1;   b=b>>1;
            cbit = c & 1;   c=c>>1;
            if((abit | bbit) != cbit){
                if((abit==1 && bbit==1) && cbit==0){
                    ans = ans + 2;
                    continue;
                }
                ans = ans + 1;
            }
        }
        return ans;
    }
};
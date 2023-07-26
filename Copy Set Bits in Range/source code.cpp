class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        int temp=1<<(r-1);
        for(int i=r-2; i>=(l-1); i--){
            temp = temp | (1 << i);
        }
        
        temp = temp & y;
        x = x | temp;
        return x;
    }
};
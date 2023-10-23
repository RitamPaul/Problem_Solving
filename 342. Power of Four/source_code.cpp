class Solution {
public:
    int mask;
    Solution(){
        mask = 0;
        for(int i=2; i<32; i+=2)
            mask = mask | (1 << i);
    }
    bool isPowerOfFour(int n) {
        if(n == 1)  return true;
        if(n>0 and !(n & (n-1)) and (mask & n) == n)
            return true;
        return false;
    }
};
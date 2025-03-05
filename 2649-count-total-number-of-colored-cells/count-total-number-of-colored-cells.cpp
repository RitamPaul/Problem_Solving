class Solution {
public:
    long long coloredCells(long long n) {
        return (n*(n+1)/2)*4 - (n*4) + 1;
    }
};
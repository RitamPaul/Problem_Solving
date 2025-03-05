class Solution {
public:
    long long coloredCells(long long n) {
        // right_angle_triangle - repeated_walls + 1_center_core
        return (n*(n+1)/2)*4 - (n*4) + 1;
    }
};
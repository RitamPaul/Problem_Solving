//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        int divisor = 2, dividend = n;
        while(dividend / divisor != 0){
            if(dividend % divisor == 0)
                return false;
            dividend = dividend - (dividend / divisor);
            ++divisor;
        }
        return true;
    }
};
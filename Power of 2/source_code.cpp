//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        // using BITS CONCEPT
        for(int i=0; i < sizeof(long long) * 8; ++i){
            if(n == ((long long)1 << i))
                return true;
        }
        return false;
    }
};
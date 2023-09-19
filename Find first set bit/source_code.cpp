//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n){
        int count = -1;
        while(++count < 32){
            if((1 << count) & n)
                return count+1;
        }
        return 0;
    }
};
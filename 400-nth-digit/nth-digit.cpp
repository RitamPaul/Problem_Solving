class Solution {
public:
    int findNthDigit(int n) {
        long low=1, high=9, digitcount=1, ans=-1;
        while(n > 0){
            long countnum = high - low + 1;
            long totaldigitcount = countnum * digitcount;

            if(n <= totaldigitcount){
                long skipnumfromleft = n / digitcount;
                n = n % digitcount;
                long numfromleft = low + (skipnumfromleft - 1);
                
                // last digit of current num is answer
                if((n % digitcount) == 0){
                    ans = numfromleft % 10;
                }
                
                // 1st digit of next num is answer
                else{
                    long num = numfromleft + 1;
                    long removefromright = digitcount - n;
                    while(removefromright--)
                        num /= 10;
                    ans = num % 10;                    
                }
                n = 0;
            }
            else{
                low = (low * 10) + 0;
                high = (high * 10) + 9;
                ++digitcount;
                n -= totaldigitcount;
            }
        }
        return ans;
    }
};
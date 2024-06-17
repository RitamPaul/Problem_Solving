class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0)
            return true;
        long long low=0, high=sqrt(c-1)+1;
        while(low <= high){
            if((low*low)+(high*high) == c)
                return true;
            else if((low*low)+(high*high) < c)
                ++low;
            else
                --high;
        }
        return false;
    }
};
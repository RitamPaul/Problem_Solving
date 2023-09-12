class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long sum = 1;
        for(int i=2; i<=sqrt(N); ++i){
            if(N % i == 0){
                sum += i;
                sum += (N / i);
            }
        }
        if(sum == N and N != 1)        return 1;
        else                return 0;
    }
};
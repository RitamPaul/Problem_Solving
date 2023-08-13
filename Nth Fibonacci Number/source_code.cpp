class Solution {
  public:
    int mod = 1000000007;
    int nthFibonacci(int n){
        int count=1, cur=1, prev=0;
        while(count<n){
            int sum = ((cur % mod) + (prev % mod)) % mod;
            prev = cur;
            cur = sum;
            ++count;
        }
        return cur;
    }
};
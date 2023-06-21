#define mod 1000000007

class Solution {
  public:
    int sumOfNaturals(int n) {
        return (  (long long)(n % mod) * ((n+1) % mod) / 2  ) % mod;
    }
};
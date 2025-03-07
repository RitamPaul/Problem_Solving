class Solution {
public:
    bool prime[(int)1e6+1];
    // sieve of eratosthenes
    Solution() {
        memset(prime, true, sizeof prime);
        prime[0] = prime[1] = false;
        for(int i=2; i<(int)1e6+1; ++i) {
            if(prime[i]) {
                // mark all its multiples as false
                for(long long mul=(long long)i*i; mul<=(int)1e6; mul+=i)
                    prime[mul] = false;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int diff=INT_MAX, first, second, prev=-1;
        for(int i=left; i<=right; ++i) {
            if(prime[i]) {
                // starting
                if(prev==-1) {
                    prev = i;
                    continue;
                }
                int curdif = i - prev;
                if(curdif < diff){
                    diff = curdif;
                    first = prev;
                    second = i;
                }
                prev = i;
            }
        }
        if(diff==INT_MAX)
            return {-1,-1};
        return {first,second};
    }
};
class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int gcd = arr[0];
        for(int i=1; i<n; ++i){
            int divisor=min(gcd, arr[i]);
            int dividend=max(gcd, arr[i]);
            int rem = dividend % divisor;
            while(rem>0){
                dividend = divisor;
                divisor = rem;
                rem = dividend % divisor;
            }
            gcd = divisor;
        }
        return gcd;
    }
};
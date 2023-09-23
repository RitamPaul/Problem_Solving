class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n){
        long long rightsum = 0, leftsum = 0;
        for(int i = 0; i<n; ++i)
            rightsum += a[i];
        for(int i = 0; i<n; ++i){
            rightsum -= a[i];
            if(leftsum == rightsum)
                return i+1;
            leftsum += a[i];
        }
        return -1;
    }
};
class Solution{
    public:
    long long int sum, c0, c1;
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	sum = 0;
    	for(int i = 0; i < 32; ++i){
    	    c0 = 0, c1 = 0;
    	    for(int j=0; j<n; ++j){
    	        if(arr[j] & (1 << i))   ++c1;
    	        else                    ++c0;
    	    }
    	    sum += (c1 * c0) * pow(2, i);
    	}
    	return sum;
    }
};
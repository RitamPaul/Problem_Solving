class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i = max(1, n-32); i <= n; ++i){
	        if(i + csb(i) == n)
	            return 0;
	    }
	    return 1;
	}
	int csb(int n){
	    int count = 0;
	    while(n > 0){
	        n = n & (n-1);
	        ++count;
	    }
	    return count;
	}
};
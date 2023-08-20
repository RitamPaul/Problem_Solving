class Solution{
public:	
    int lower(int arr[], int &n, int &target, int start){
        int low=start, high=n-1, ans=-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] < target)
                low = mid + 1;
            else{
                if(arr[mid] == target)
                    ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    int upper(int arr[], int &n, int &target, int start){
        int low=start, high=n-1, ans=-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] > target)
                high = mid - 1;
            else{
                if(arr[mid] == target)
                    ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int start = lower(arr, n, x, 0);
	    if(start != -1){
	        int end = upper(arr, n, x, start);
	        return end-start+1;
	    }
	    return 0;
	}
};
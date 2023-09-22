class Solution
{
    public:
    int lower(int arr[], int n, int target){
        int low = 0, mid, high = n-1, ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] >= target){
                if(arr[mid] == target)
                    ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    int upper(int arr[], int n, int target){
        int low = 0, mid, high = n-1, ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] <= target){
                if(arr[mid] == target)
                    ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x ){
        int first = lower(arr, n, x);
        if(first == -1)
            return {-1, -1};
        int last = upper(arr, n, x);
        return {first, last};
    }
};
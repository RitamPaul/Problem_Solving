class Solution {
public:
    long long search(int row, int col, int target){
        // printf("[%d]", target);
        long long count = 0;
        // for each row
        for(long long i=1; i<=min(target, row); ++i){

            if(i*col < target){
                count += col;
                printf("(%d,%d)", i, count);
                continue;
            }

            // binary search in each row
            long long low=1, high=col, ans, mid;
            while(low <= high){
                mid = low + (high - low) / 2;
                if(target <= i*mid){
                    ans = mid;
                    high = mid - 1;
                }
                else if(i*mid < target)
                    low = mid + 1;
            }
            count += (i*ans == target ? ans : ans-1);
            // printf("(%d,%d)", i, count);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        long long low = 1, high = (long long)m * n, mid, ans, countleft;
        while(low <= high){
            mid = low + (high - low) / 2;
            countleft = search(m, n, mid);
            // if(countleft == k)
            //     return mid;
            if(k <= countleft){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    bool possibleInTime(vector<int>& ranks, int cars, long long time){
        int n=ranks.size();
        for(int i=n-1; i>=0; --i) {
            if(cars <= 0)
                break;
            // within given time how many cars can be repaired by this human ?
            int maxCarRepairable = floor( sqrt(time/ranks[i]) );
            cars = cars - maxCarRepairable;
        }
        return cars<=0 ? true : false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        // since answer does not depend on original index
        sort(ranks.begin(), ranks.end());
        
        // lowest time = lowest rank * 1car * 1car
        long long low = 1;
        // highest time = highest rank * all car * all car
        long long high = (long long)ranks[n-1] * cars * cars;
        long long mid, ans;
        while(low <= high) {
            mid = low + (high - low) / 2;
            bool valid = possibleInTime(ranks, cars, mid);
            if(valid){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
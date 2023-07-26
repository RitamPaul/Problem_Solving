class Solution {
public:
    bool check(vector<int> &dist, double hour, int sp){
        int n=dist.size();
        double temphour=0;
        for(auto i=0; i<n; i++){
            temphour += (double)dist[i] / sp;
            if(i != n-1)
                temphour = ceil(temphour);
        }
        return temphour <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size(), ans=-1;
        if(hour <= n-1)     return ans;
        int high=INT_MAX, low=1, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(check(dist, hour, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
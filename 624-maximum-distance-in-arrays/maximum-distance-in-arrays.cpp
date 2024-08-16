class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        vector<pair<int,int>> mini, maxi;

        for(int i=0; i<n; ++i){
            int m = arrays[i].size();
            mini.push_back({arrays[i][0], i});
            maxi.push_back({arrays[i][m-1], i});
        }

        sort(mini.begin(), mini.end());
        sort(maxi.begin(), maxi.end());

        int mini1val=mini[0].first;
        int mini1pos=mini[0].second;
        int maxi1val=maxi[n-1].first;
        int maxi1pos=maxi[n-1].second;

        if(mini1pos == maxi1pos){
            int mini2val = mini[1].first;
            int maxi2val = maxi[n-2].first;
            int big1 = maxi2val - mini1val;
            int big2 = maxi1val - mini2val;
            return max(big1, big2);
        }
        return maxi1val - mini1val;
    }
};
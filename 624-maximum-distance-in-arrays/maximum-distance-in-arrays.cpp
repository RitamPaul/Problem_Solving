class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        auto n{arrays.size()};
        vector<pair<int,int>> mini, maxi;

        for(auto i=0; i<n; ++i){
            auto m{arrays[i].size()};
            mini.push_back({arrays[i][0], i});
            maxi.push_back({arrays[i][m-1], i});
        }

        sort(mini.begin(), mini.end());
        sort(maxi.begin(), maxi.end());

        auto mini1val{mini[0].first};
        auto mini1pos{mini[0].second};
        auto maxi1val{maxi[n-1].first};
        auto maxi1pos{maxi[n-1].second};

        if(mini1pos == maxi1pos){
            auto mini2val{mini[1].first};
            auto maxi2val{maxi[n-2].first};
            auto big1{maxi2val - mini1val};
            auto big2{maxi1val - mini2val};
            return max(big1, big2);
        }
        return maxi1val - mini1val;
    }
};
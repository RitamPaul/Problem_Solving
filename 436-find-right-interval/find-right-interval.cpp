bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}
class Solution {
public:
    int search(vector<pair<int,int>> &temp, int endtime){
        int n=temp.size(), low=0, high=n-1, ans=-1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(temp[mid].first >= endtime){
                ans = temp[mid].second;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& interval) {
        int n = interval.size();
        vector<pair<int,int>> temp;

        for(int i=0; i<n; ++i)
            temp.push_back({interval[i][0], i});
        
        sort(temp.begin(), temp.end(), cmp);
        
        vector<int> ans;
        for(int i=0; i<n; ++i){
            int endtime = interval[i][1];
            int ind = search(temp, endtime);
            ans.push_back(ind);
        }
        return ans;
    }
};
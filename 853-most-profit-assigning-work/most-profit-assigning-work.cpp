bool mycmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}
class Solution {
public:
    int func(int &work, vector<pair<int,int>> &temp){
        int low=0, high=temp.size()-1, ind=-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(temp[mid].first <= work){
                ind = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(ind==-1)     return 0;
        int maxi=INT_MIN;
        for(auto i=0; i<=ind; i++)
            maxi = max(maxi, temp[i].second);
        return maxi;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> temp(profit.size());
        for(auto i=0; i<profit.size(); i++)
            temp[i] = {difficulty[i], profit[i]};
        sort(temp.begin(), temp.end(), mycmp);
        int sum=0;
        for(auto &work:worker){
            sum += func(work, temp);
        }
        return sum;
    }
};
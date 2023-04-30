class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<long long, int> mp;
        for(auto v:intervals){
            mp[v[0]]++;
            mp[v[1]+1]--;
        }
        
        int ans=-1, psum=0;
        for(auto p:mp){
            if(p.second < 0){
                if(psum >= k)
                    ans = p.first - 1;
            }
            psum += p.second;
            if(psum >= k)
                ans = p.first;
        }
        return ans;
    }
};
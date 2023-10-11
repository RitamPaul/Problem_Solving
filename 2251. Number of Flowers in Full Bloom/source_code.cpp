class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        mp[0] = 0;
        for(auto &v : flowers){
            mp[v[0]] += 1;
            mp[ v[1]+1 ] -= 1;
        }
        int prev = 0;
        for (auto &p : mp){
            p.second = prev + p.second;
            prev = p.second;
        }
        int n = people.size();
        vector<int> ans(n);
        for(int i = 0; i<n; ++i){
            if(mp.find(people[i]) != mp.end())
                ans[i] = mp[ people[i] ];
            else{
                auto it = mp.lower_bound( people[i] );
                --it;
                ans[i] = (*it).second;
            }
        }
        return ans;
    }
};
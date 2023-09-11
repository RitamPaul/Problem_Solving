class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        int ind = 0;
        for(int i=0; i<n; ++i)
            mp[group[i]].push_back(i);
        for(auto &p:mp){
            ans.push_back({});
            for(auto &index:p.second){
                if(ans.back().size() != p.first)
                    ans.back().push_back(index);
                else
                    ans.push_back({index});
            }
        }
        return ans;
    }
};
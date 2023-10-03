class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i:nums)
            ++mp[i];
        int ans = 0;
        for(auto &p:mp){
            if(p.second > 1)
                ans += ((p.second * (p.second - 1)) / 2);
        }
        return ans;
    }
};
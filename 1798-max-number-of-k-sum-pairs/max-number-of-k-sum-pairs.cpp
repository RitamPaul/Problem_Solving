class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(const auto &i : nums)
            ++mp[i];
        
        int count=0;
        for(const auto &i : nums){
            if(mp[i]){
                --mp[i];
                if(mp[k-i]){
                    --mp[k-i];
                    ++count;
                }
                else
                    ++mp[i];
            }
        }
        return count;
    }
};
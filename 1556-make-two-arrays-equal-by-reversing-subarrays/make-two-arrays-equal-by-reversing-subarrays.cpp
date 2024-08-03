class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(const auto &i : target){
            ++mp[i];
        }

        for(const auto &i : arr){
            if(!mp.count(i))
                return false;
            
            --mp[i];
            if(mp[i] == 0)
                mp.erase(i);
        }

        return true;
    }
};
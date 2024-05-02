class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size(), ans=-1;
        unordered_set<int> s;
        for(auto &i : nums)
            s.insert(i);
        for(auto &i : s){
            if(i > 0 and s.count(-1*i))
                ans = max(ans, i);
        }
        return ans;
    }
};
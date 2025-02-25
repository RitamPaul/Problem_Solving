class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<string,int> mp;
        unsigned long long ans = 0;
        int mod = 1000000000+7;
        // initialise
        mp["odd"] = 0;
        mp["even"] = 0;
        int prefixsum = 0;
        for(const auto &i : arr){
            prefixsum += i;
            // even
            if(prefixsum%2 == 0){
                ans += (mp["odd"]);
                ++mp["even"];
            }
            // odd
            else{
                ans += (mp["even"]);
                ++ans;
                ++mp["odd"];
            }
        }
        return ans%mod;
    }
};
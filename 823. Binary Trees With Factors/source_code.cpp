class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        unordered_map<int, long long> mp;
        sort(arr.begin(), arr.end());
        for(auto &i : arr)
            ++mp[i];
        for(int i = 1; i < n; ++i){
            long long extracount = 0;
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0 and mp.find(arr[i] / arr[j]) != mp.end()){
                    long long first = mp[arr[j]];
                    long long second = mp[arr[i] / arr[j]];
                    extracount += first * second;
                }
            }
            mp[arr[i]] = mp[arr[i]] + extracount;
        }
        int ans = 0;
        for(auto &p : mp){
            ans = ((ans % mod) + (p.second % mod)) % mod;
        }
        return ans;
    }
};
class Solution{
  public:
    int longestKSubstr(string s, int k){
        unordered_map<char,int> mp;
        int n=s.size(), ans=-1, low=0, high=0;
        while(high < n){
            ++mp[s[high]];
            
            // added to map and map size > k
            if(mp.size() > k){
                // answer calculation
                ans = max(ans, high-low);
                
                char remove;
                while(true){
                    remove = s[low];
                    --mp[remove];
                    ++low;
                    if(mp[remove]==0)
                        break;
                }
                mp.erase(remove);
            }
            ++high;
        }
        if(mp.size() == k){
            ans = max(ans, high-low);
        }
        return ans;
    }
};
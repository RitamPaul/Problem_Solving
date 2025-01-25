class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        // map of prefixsum->index
        unordered_map<int,int> mp;
        int n=arr.size(), sum=0, ans=0;
        for(auto &i : arr){
            if(i==0)
                i=-1;
        }
        for(int i=0; i<n; ++i){
            sum+=arr[i];
            if(sum==0)
                ans=max(ans, i+1);
            else{
                int toremove=sum;
                if(mp.count(toremove))
                    ans=max(ans, i-mp[toremove]);
            }
            if(!mp.count(sum))
                mp[sum]=i;
        }
        return ans;
    }
};
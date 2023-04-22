class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int> help;
        for(auto i:arr)
            help.push_back(i);
        sort(help.begin(), help.end());
        
        unordered_map<int, int> freq;
        for(auto i:help){
            freq[i]++;
        }
        
        unordered_map<int, long long> acu;
        acu[help[0]]=0;
        for(int i=1; i<help.size(); ++i){
            if(help[i]!=help[i-1]){
                acu[help[i]] = acu[help[i-1]] + (help[i-1] * freq[help[i-1]]);
            }
        }
        
        vector<long long> ans;
        for(int i=0; i<arr.size(); ++i){
            ans.push_back(acu[arr[i]]);
        }
        return ans;
    }
};
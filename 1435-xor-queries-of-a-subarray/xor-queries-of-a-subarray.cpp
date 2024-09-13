int prefix[3*(int)1e4];
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        memset(prefix, 0, sizeof prefix);
        int n = arr.size();
        prefix[0] = arr[0];

        for(int i=1; i<n; ++i)
            prefix[i] = prefix[i-1] ^ arr[i];
        
        vector<int> ans;
        for(const auto &q : queries)
            ans.push_back( prefix[q[1]] ^ prefix[q[0]] ^ arr[q[0]] );
        return ans;
    }
};
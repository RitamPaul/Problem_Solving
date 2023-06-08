class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> v(n);
        for(auto i=0; i<n; i++)
            v[i] = i+1;
        
        for(auto i=1; i<k; i++){
            next_permutation(v.begin(), v.end());
        }
        string ans="";
        for(auto i:v){
            ans = ans + to_string(i);
        }
        return ans;
    }
};
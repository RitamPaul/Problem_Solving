class Solution{
    public:
    void func(string &s, string temp, vector<string> &ans, int ind){
        int n=s.size();
        //base case
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        
        for(auto i=0; i<n; i++){
            if(s[i]!=0){
                temp.push_back(s[i]);
                s[i] = 0;
                func(s, temp, ans, ind+1);
                s[i] = temp[ind];
                temp.pop_back();
            }
        }
        return;
    }
    vector<string> permutation(string S){
        vector<string> ans;
        string temp="";
        /*
        int fact=1;
        for(auto i=S.size(); i>1; i--)
            fact *= i;
        
        for(auto i=1; i<=fact; i++){
            ans.push_back(S);
            next_permutation(S.begin(), S.end());
        }
        */
        func(S, temp, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
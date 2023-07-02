class Solution {
public:
    void func(vector<int> &cookie, int ind, int k, vector<int> &child, int &mini, int &maxi){
        //base case
        if(ind >= cookie.size()){
            mini = min(mini, maxi);
            return;
        }

        //recursion
        for(auto i=0; i<k; i++){
            child[i] += cookie[ind];
            int newmaxi = maxi;
            maxi = max(maxi, child[i]);
            func(cookie, ind+1, k, child, mini, maxi);
            child[i] -= cookie[ind];
            maxi = newmaxi;
        }
        return;
    }
    int distributeCookies(vector<int>& cookie, int k) {
        vector<int> child(k,0);
        int mini=INT_MAX, maxi=INT_MIN;
        func(cookie, 0, k, child, mini, maxi);
        return mini;
    }
};
class Solution{   
public:
    bool equal(string &s1, string &s2, int k){
        for(auto i=0; i<k; i++){
            if(i>=s1.size() || i>=s2.size() || s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    int klengthpref(string arr[], int n, int k, string str){    
        int ans=0;
        for(auto i=0; i<n; i++){
            if(equal(arr[i], str, k))
                ans++;
        }
        return ans;
    }
};
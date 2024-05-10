//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(int ind, vector<int> &arr, int sum, int &k, set<vector<int>> &s,
                vector<int> &ans){
        
        // calculations
        if(sum==k){
            s.insert(ans);
            return;
        }
        
        // base case
        if(ind>=arr.size() or arr[ind]>k)       return;
        
        // recursive case
        if(sum+arr[ind] <= k){
            ans.push_back(arr[ind]);
            helper(ind+1, arr, sum+arr[ind], k, s, ans);
            ans.pop_back();
        }
        helper(ind+1, arr, sum, k, s, ans);
        
        // return from current state
        return;
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(), arr.end());
        set<vector<int>> s;
        vector<int> ans;
        helper(0, arr, 0, k, s, ans);
        vector<vector<int>> temp;
        for(auto &v : s)
            temp.push_back(v);
        return temp;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool helper(int arr[], int ind, int target, vector<vector<int>> &vis){
        //base case
        if(ind == 0)
            return target==0;
        if(target == 0)
            return 1;
            
        //dp found case
        if(vis[ind][target] != -1)
            return vis[ind][target];
        
        //recursive case
        int nottake = 0, take = 0;
        //don't consider that item
        nottake = helper(arr, ind-1, target, vis);
        if(nottake == 1)
            return vis[ind][target] = nottake;
            
        //consider that item
        if(target >= arr[ind])
            take = helper(arr, ind-1, target-arr[ind], vis);
            
        //return from current state
        return (vis[ind][target] = take + nottake);
        
    }
    int equalPartition(int N, int arr[]){
        int sum = accumulate(arr, arr+N, 0);
        if(sum % 2 != 0)
            return 0;
        int target = sum / 2;
        vector<vector<int>> vis(N, vector<int>(target+1, -1));
        return helper(arr, N-1, target, vis);
    }
};
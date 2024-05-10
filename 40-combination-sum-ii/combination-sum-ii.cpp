class Solution {
public:
    int n;
    void helper(int ind, vector<int> &arr, int target, vector<int> &temp,
                vector<vector<int>> &ans){
        // base case
        if(target==0){
            ans.push_back(temp);
            return;
        }

        // recursive case
        for(int i=ind; i<n; ++i){
            if(i>ind and arr[i]==arr[i-1])  continue;
            if(arr[i]>target)               break;
            temp.push_back(arr[i]);
            helper(i+1, arr, target-arr[i], temp, ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0, arr, target, temp, ans);
        return ans;
    }
};
class Solution {
public:
    int find(vector<int> &arr, int ind){
        int start = 0, end = ind, ans;
        if(arr[0] < 0)
            return 0;
        else if(arr[arr.size()-1] >= 0)
            return arr.size();
        while(start <= end){
            int mid = (start + end) / 2;
            if(arr[mid] < 0){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        if(grid[0][0] < 0){
            for(auto arr:grid){
                ans = ans + arr.size();
            }
            return ans;
        }
        int ind=grid[0].size()-1;
        for(auto arr:grid){            
            ind = find(arr, ind);
            if(ind == arr.size())
                continue;
            ans = ans + (arr.size() - ind);
        }
        return ans;
    }
};
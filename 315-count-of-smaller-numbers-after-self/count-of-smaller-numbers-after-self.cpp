class Solution {
public:
    int n;
    int search(vector<pair<int,int>>&arr, int start, int end, int target){
        int ans=end+1, mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(arr[mid].first >= target){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
    void mergesort(vector<pair<int,int>> &arr, int start, int end, vector<int> &ans){
        // base case
        if(start >= end)        return;
        
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid, ans);
        mergesort(arr, mid+1, end, ans);
        
        // before merge, some calculations
        for(int i=start; i<=mid; ++i){
            // binary search
            int rightind = search(arr, mid+1, end, arr[i].first);
            int rightcount = rightind - (mid+1);
            // auto rightind = upper_bound(arr.begin()+mid+1, arr.begin()+end+1, arr[i], cmp);
            // int rightcount = rightind - (arr.begin()+mid+1);
            ans[ arr[i].second ] += rightcount;
        }
        
        // merge
        vector<pair<int,int>> temp(end-start+1);
        
        int i=start, j=mid+1, k=0;
        
        while(i <= mid and j <= end){
            if(arr[i].first < arr[j].first){
                // // binary search
                // int rightind = search(arr, mid+1, end, arr[i].first);
                // int rightcount = rightind - (mid+1);
                // // auto rightind = upper_bound(arr.begin()+mid+1, arr.begin()+end+1, arr[i], cmp);
                // // int rightcount = rightind - (arr.begin()+mid+1);
                // ans[ arr[i].second ] += rightcount;
                
                temp[k] = arr[i];
                ++i;
                ++k;
            }
            else if(arr[i].first == arr[j].first){
                temp[k] = arr[i];
                ++i;
                ++k;
                temp[k] = arr[j];
                ++j;
                ++k;
            }
            else{
                temp[k] = arr[j];
                ++j;
                ++k;
            }
        }
        while(i <= mid){
            // // binary search
            // int rightind = search(arr, mid+1, end, arr[i].first);
            // int rightcount = rightind - (mid+1);
            // // auto rightind = upper_bound(arr.begin()+mid+1, arr.begin()+end+1, arr[i], cmp);
            // // int rightcount = rightind - (arr.begin()+mid+1);
            // ans[ arr[i].second ] += rightcount;
            
            temp[k] = arr[i];
            ++i;
            ++k;
        }
        while(j <= end){
            temp[k] = arr[j];
            ++j;
            ++k;
        }
        
        
        // copy to original array
        for(int i=0; i<end-start+1; ++i)
            arr[start + i] = temp[i];
        
        return;
    }
    vector<int> countSmaller(vector<int>& ans) {
        n = ans.size();
        vector<pair<int,int>> arr;
        
        for(int i=0; i<n; ++i){
            arr.push_back({ans[i], i});
            ans[i] = 0;
        }
        
        mergesort(arr, 0, n-1, ans);
        return ans;
    }
};
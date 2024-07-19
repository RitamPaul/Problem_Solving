//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

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
            int rightind = search(arr, mid+1, end, arr[i].first);
            int rightcount = rightind - (mid+1);
            // printf("(%d,%d-%d,%d) ",start, end, arr[i].first, rightcount);
            ans[ arr[i].second ] += rightcount;
        }
        
        // merge
        vector<pair<int,int>> temp(end-start+1);
        
        int i=start, j=mid+1, k=0;
        
        while(i <= mid and j <= end){
            // binary search
            // auto rightind = search(arr, mid+1, end, arr[i].first);
            // int rightcount = rightind - (mid+1);
            // printf("(%d,%d) ", arr[i].first, rightcount);
            // ans[ arr[i].second ] += rightcount;
            
            if(arr[i].first < arr[j].first){
                temp[k] = {arr[i].first, arr[i].second};
                ++i;
                ++k;
            }
            else if(arr[i].first == arr[j].first){
                temp[k] = {arr[i].first, arr[i].second};
                ++i;
                ++k;
                temp[k] = {arr[j].first, arr[j].second};
                ++j;
                ++k;
            }
            else{
                temp[k] = {arr[j].first, arr[j].second};
                ++j;
                ++k;
            }
        }
        while(i <= mid){
            // binary search
            // auto rightind = search(arr, mid+1, end, arr[i].first);
            // int rightcount = rightind - (mid+1);
            // printf("(%d,%d) ", arr[i].first, rightcount);
            // ans[ arr[i].second ] += rightcount;
            
            temp[k] = {arr[i].first, arr[i].second};
            ++i;
            ++k;
        }
        while(j <= end){
            temp[k] = {arr[j].first, arr[j].second};
            ++j;
            ++k;
        }
        
        
        // printf("{[%d,%d]-", start, end);
        // copy to original array
        for(int i=0; i<end-start+1; ++i){
            arr[start + i].first = temp[i].first;
            arr[start + i].second = temp[i].second;
            // printf("{%d,%d}", arr[start+i].first, arr[start+i].second);
        }
        // printf("} ");
        
        return;
    }
    vector<int> constructLowerArray(vector<int> &ans) {
        // code here
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


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        if(n==1)
            return (arr[0]==target) ? 0 : -1;
            
        int mini=min(arr[0],arr[1]);
        int maxi=max(arr[n-1],arr[n-2]);
        int low=0, high=n-1, mid, cur;
        
        while(low<=high){
            mid = low + (high-low) / 2;
            cur = arr[mid];
            if(cur==target)
                return mid;
            // mid-1 is valid index
            if(low<=mid-1 and mid-1<=high){
                if(arr[mid-1]==target)
                    return mid-1;
                // current item is moved LEFT
                if(arr[mid-1]>arr[mid])
                    cur=arr[mid-1];
            }
            // mid+1 is valid index
            if(low<=mid+1 and mid+1<=high){
                if(arr[mid+1]==target)
                    return mid+1;
                // current item is moved RIGHT
                if(arr[mid]>arr[mid+1])
                    cur=arr[mid+1];
            }
            
            // reduce search space
            if(target > cur)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
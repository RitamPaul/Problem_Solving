//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lower(vector<int> &arr, int target){
        int n=arr.size(), low=0, high=n-1, mid, ans=-1;
        while(low <= high){
            mid=low+(high-low)/2;
            if(arr[mid]==target)
                ans = mid;
            if(arr[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
    int upper(vector<int> &arr, int target){
        int n=arr.size(), low=0, high=n-1, mid, ans=-1;
        while(low <= high){
            mid=low+(high-low)/2;
            if(arr[mid]==target)
                ans = mid;
            if(arr[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int left = lower(arr, target);
        int right = upper(arr, target);
        if(left >= 0 and right >= 0)
            return right-left+1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
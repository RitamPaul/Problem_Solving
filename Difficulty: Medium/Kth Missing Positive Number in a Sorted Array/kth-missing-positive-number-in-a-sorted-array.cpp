//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        // count of items missing at index - ind =
        // arr[ind] - (ind+1)
        int n=arr.size(), l=0, h=n-1, m, ans=-1;
        while(l<=h){
            m = l + (h - l) / 2;
            int missingcount = arr[m] - (m+1);
            if(missingcount>=k){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        if(ans==0)
            return 1+(k-1);
        else if(ans==-1)
            return arr.back()+(k-(arr.back()-n));
        // missing count at prev index
        int missprev = arr[ans-1]-ans;
        // remaining missing count
        int rem = k-missprev;
        return arr[ans-1]+rem;
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
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
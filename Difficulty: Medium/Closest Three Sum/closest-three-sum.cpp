//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int sum, dis=INT_MAX, ans, start, end;
        for(int i=0; i<n; ++i){
            sum = target - arr[i];
            start = i+1;
            end = n-1;
            while(start < end){
                // absolute distance of found triplet - target value is less
                if(abs(sum - (arr[start] + arr[end])) < dis){
                    ans = arr[i] + arr[start] + arr[end];
                    dis = abs(sum - (arr[start] + arr[end]));
                }
                // absolute distance of found triplet - found answer is equal
                else if(abs(sum - (arr[start] + arr[end])) == dis)
                    ans = max(ans, arr[i] + arr[start] + arr[end]);
                
                // target value achieved : immediate return
                if(arr[start] + arr[end] == sum)
                    return target;
                else if(arr[start] + arr[end] > sum)
                    --end;
                else
                    ++start;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
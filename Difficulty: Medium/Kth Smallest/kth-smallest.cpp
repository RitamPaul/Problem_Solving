//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

const int max_size = 1e6 + 1; // max value possible in given array
int freq[max_size];
int sorted[max_size];
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        // implementing COUNT SORT Algo here...
        int n=arr.size();
        
        // memset(freq, 0, sizeof freq); // big-O(max_item)
        // memset(sorted, 0, sizeof sorted); // big-O(max_item)
        
        int max_size = *max_element(arr.begin(), arr.end()) + 1;
        vector<int> freq(max_size, 0); // big-O(max_item)
        vector<int> sorted(max_size, 0); // big-O(max_item)
        
        // counting frequencies -> big-O(n)
        for(int i=0; i<n; ++i)
            ++freq[arr[i]];
        
        // prefix sum of counting frequencies -> big-o(max_item)
        for(int i=1; i<max_size; ++i)
            freq[i] += freq[i-1];
        
        // building sorted array -> big-O(n)
        for(int i=n-1; i>=0; --i){
            int val = arr[i];
            int smallcountuptoval = freq[val]; // general indexing
            
            sorted[smallcountuptoval-1] = val;
            
            --freq[val];
        }
        
        return sorted[k-1];
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
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
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int freq[1000000+1];
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        memset(freq, 0, sizeof freq);
        int maxi = INT_MIN;
        for(auto &i : citations){
            ++freq[i];
            maxi = max(maxi, i);
        }
        
        for(int i=maxi-1; i>=0; --i)
            freq[i] += freq[i+1];
        
        int ans;
        for(int i=0; i<=maxi; ++i){
            if(freq[i] >= i)
                ans = i;
            else
                break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> temp;
        int n=arr.size();
        for(int i=0; i<n; ++i) {
            if(temp.empty() || temp.back()<arr[i])
                temp.push_back(arr[i]);
            else{
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[index] = arr[i];
            }
        }
        return temp.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        sort(arr.begin(), arr.end());
        
        bool leftinc = true;
        int left=0, right=n-1;
        long long sum = 0;
        
        while(true){
            sum += abs(arr[left] - arr[right]);
            if(leftinc)
                ++left;
            else
                --right;
            if(left == right){
                left = 0;
                sum += abs(arr[left] - arr[right]);
                break;
            }
            leftinc = not leftinc;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
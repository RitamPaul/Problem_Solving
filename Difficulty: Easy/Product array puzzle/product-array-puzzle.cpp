//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long mul{1}, countz{0};
        for(const auto &i : nums){
            if(i > 0)
                mul *= i;
            else
                ++countz;
        }
        
        for(auto &i : nums){
            if(i > 0){
                if(countz > 0)
                    i = 0;
                else
                    i = mul / i;
            }
            // integer is 0
            else{
                if(countz > 1)
                    i = 0;
                else
                    i = mul;
            }
        }
        
        return nums;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
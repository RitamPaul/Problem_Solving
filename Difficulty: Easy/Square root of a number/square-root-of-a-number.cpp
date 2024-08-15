//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long ans{0}, mid{0}, left_prev{0}, right_fast{1};
        
        while(right_fast * right_fast <= n){
            left_prev = right_fast;
            right_fast *= 2;
        }
        
        while(left_prev <= right_fast){
            mid = left_prev + (right_fast - left_prev) / 2;
            if(mid * mid <= n){
                ans = mid;
                left_prev = mid + 1;
            }
            else
                right_fast = mid - 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
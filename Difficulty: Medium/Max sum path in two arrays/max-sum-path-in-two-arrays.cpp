//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ans;
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        ans = 0;
        int n1=arr1.size(), n2=arr2.size();
        int i, j, sum1=arr1[0], sum2=arr2[0];
        
        for(i=0, j=0; (i<n1 and j<n2); ){
            // equal item detected
            if(arr1[i] == arr2[j]){
                ans += max(sum1, sum2);
                ++i;
                sum1 = (i<n1) ? arr1[i] : 0;
                ++j;
                sum2 = (j<n2) ? arr2[j] : 0;
            }
            
            // 1st array item is greater
            else if(arr1[i] > arr2[j]){
                ++j;
                sum2 += (j<n2) ? arr2[j] : 0;
            }
            
            // 2nd array item is greater
            else{
                ++i;
                sum1 += (i<n1) ? arr1[i] : 0;
            }
        }
        if(i>=n1){
            for(int k=j+1; k<n2; ++k)
                sum2 += arr2[k];
        }
        if(j>=n2){
            for(int k=i+1; k<n1; ++k)
                sum1 += arr1[k];
        }
        
        ans += max(sum1, sum2);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
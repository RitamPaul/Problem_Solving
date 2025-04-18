//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        // map of prefixsum->index
        unordered_map<int,int> mp;
        int n=arr.size(), sum=0, ans=0;
        for(auto &i : arr){
            if(i==0)
                i=-1;
        }
        for(int i=0; i<n; ++i){
            sum+=arr[i];
            if(sum==0)
                ans=max(ans, i+1);
            else{
                int toremove=sum;
                if(mp.count(toremove))
                    ans=max(ans, i-mp[toremove]);
            }
            if(!mp.count(sum))
                mp[sum]=i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends
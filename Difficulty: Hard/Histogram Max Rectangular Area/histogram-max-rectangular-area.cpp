//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int ans=INT_MIN, curans, topheight, rightsmall, leftsmall;
        stack<int> stk;
        for(int i=0; i<n; ++i){
            int cur=arr[i];
            while(stk.size() and cur<=arr[stk.top()]){
                topheight = arr[stk.top()];
                stk.pop();
                rightsmall = i;
                if(stk.size()){
                    leftsmall = stk.top();
                    curans = topheight*(rightsmall-(leftsmall+1));
                    ans = max(ans, curans);
                }
                else{
                    curans = topheight*i;
                    ans = max(ans, curans);
                }
            }
            stk.push(i);
        }
        while(stk.size()){
            topheight = arr[stk.top()];
            stk.pop();
            rightsmall = n;
            if(stk.size()){
                leftsmall = stk.top();
                curans = topheight*(rightsmall-(leftsmall+1));
                ans = max(ans, curans);
            }
            else{
                curans = topheight*n;
                ans = max(ans, curans);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
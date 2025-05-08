//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size(), dif1=arr[1]-arr[0], cnt1=1, num1=arr[0], dif2=0, cnt2=0, num2=0;
        if(n==2)
            return arr.back()+(arr[1]-arr[0]);
        for(int i=2; i<n; ++i){
            int prev=arr[i-1], cur=arr[i], curdif=cur-prev;
            if(curdif==dif1){
                ++cnt1;
                num1=prev;
            }
            else{
                dif2=curdif;
                ++cnt2;
                num2=prev;
            }
        }
        // same diff throughout - dif2 not initialised
        if(cnt2==0)
            return arr.back()+dif1;
        else if(cnt1==1)
            return num1+dif2;
        return num2+dif1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
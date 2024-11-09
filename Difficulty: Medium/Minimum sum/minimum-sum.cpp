//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        string num1="", num2="";
        for(int i=0; i<n; ){
            if(arr[i]!=0 or (arr[i]==0 and num1.size()))
                num1 += ('0' + arr[i]);
            ++i;
            if(i<n and (arr[i]!=0 or (arr[i]==0 and num2.size()))){
                num2 += ('0' + arr[i]);
                ++i;
            }
        }
        // cout<<num1<<", "<<num2<<endl;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        // cout<<num1<<", "<<num2<<endl;
        
        string ans="";
        int carry=0;
        for(int i=0; i<max(num1.size(), num2.size()); ++i){
            int a=0, b=0, sum=0;
            if(i < num1.size())
                a=num1[i]-'0';
            if(i < num2.size())
                b=num2[i]-'0';
            sum = carry + a + b;
            ans += ('0' + (sum % 10));
            carry = sum / 10;
        }
        if(carry)
            ans += ('0' + carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<long long int> stk;
        long long int val, sign;
        for(const auto &s : arr) {
            // number
            if((s[0]=='-' && s.size()>1) || ('0'<=s[0] && s[0]<='9')) {
                val = 0;
                sign = 1;
                for(auto &ch : s) {
                    if(ch=='-') {
                        sign = -1;
                        continue;
                    }
                    val = (val*10) + (ch-'0');
                }
                stk.push(sign*val);
            }
            // operator
            else {
                long long int second = stk.top();
                stk.pop();
                long long int first = stk.top();
                stk.pop();
                if(s[0]=='+')
                    stk.push(first+second);
                else if(s[0]=='-')
                    stk.push(first-second);
                else if(s[0]=='*')
                    stk.push(first*second);
                else if(s[0]=='/')
                    stk.push(first/second);
            }
        }
        return stk.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
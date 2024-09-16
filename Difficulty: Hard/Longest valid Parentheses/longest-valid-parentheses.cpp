//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    stack<int> stk;
    int end2startmap[(int)1e5 + 1];
    
    int maxLength(string& str) {
        // code here
        int n = str.size();
        int ans = 0;
        memset(end2startmap, -1, sizeof end2startmap);
        
        for(int i=0; i<n; ++i){
            // found '('
            if(str[i] == '(')
                stk.push(i);
            
            // found ')'
            else{
                if(stk.empty())
                    continue;
                
                int curstart = stk.top();
                stk.pop();
                
                int prevstart = end2startmap[curstart-1];
                
                if(prevstart != -1){
                    end2startmap[i] = prevstart;
                    ans = max(ans, i-prevstart+1);
                }
                else{
                    end2startmap[i] = curstart;
                    ans = max(ans, i-curstart+1);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends
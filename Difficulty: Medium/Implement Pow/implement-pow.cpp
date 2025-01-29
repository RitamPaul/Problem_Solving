//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        if(e==0)
            return 1;
        // else if(abs(e)==1){
        //     if(e==-1)
        //         return (double)1/b;
        //     return b;
        // }
        
        int exp=e;
        e=abs(e);
        int sign=(b<0) ? -1 : 1;
        b=abs(b);
        
        if(e%2==0)
            sign=1;
        
        double ans=1;
        while(e>0){
            if(e%2==1){
                ans*=b;
                e-=1;
                // cout<<"[ans="<<ans<<", e="<<e<<"] ";
                // printf("(ans=%f, e=%f) ",ans,e);
            }
            else{
                b*=b;
                e/=2;
                // cout<<"[ans="<<ans<<", e="<<e<<"] ";
                // printf("(ans=%f, e=%f) ",ans,e);
            }
        }
        if(exp<0)
            return ((double)1/ans)*sign;
        return (ans*sign);
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
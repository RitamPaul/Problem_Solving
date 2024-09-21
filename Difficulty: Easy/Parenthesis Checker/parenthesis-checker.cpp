//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.size();
        stack<char> stk;
        
        for(int i=0; i<n; ++i){
            if(x[i]=='(' or x[i]=='{' or x[i]=='[')
                stk.push(x[i]);
            else if(x[i]==')' and stk.size() and stk.top()=='(')
                stk.pop();
            else if(x[i]=='}' and stk.size() and stk.top()=='{')
                stk.pop();
            else if(x[i]==']' and stk.size() and stk.top()=='[')
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
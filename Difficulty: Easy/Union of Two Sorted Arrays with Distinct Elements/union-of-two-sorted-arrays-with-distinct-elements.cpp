//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int n1=a.size(), n2=b.size();
        vector<int> ans;
        int i=0, j=0;
        while(i<n1 and j<n2){
            if(a[i]<=b[j]){
                if(ans.empty() or ans.back()!=a[i])
                    ans.push_back(a[i]);
                ++i;
            }
            else{
                if(ans.empty() or ans.back()!=b[j])
                    ans.push_back(b[j]);
                ++j;
            }
        }
        while(i<n1){
            if(ans.empty() or ans.back()!=a[i])
                ans.push_back(a[i]);
            ++i;
        }
        while(j<n2){
            if(ans.empty() or ans.back()!=b[j])
                ans.push_back(b[j]);
            ++j;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
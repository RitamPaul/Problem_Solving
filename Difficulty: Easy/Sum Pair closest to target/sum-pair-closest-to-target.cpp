//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int a,b,dif=INT_MAX;
        int i=0, j=n-1;
        while(i < j){
            int sum=arr[i]+arr[j];
            if(sum==target)
                return {arr[i],arr[j]};
            else{
                int curdif=abs(target-sum);
                if(curdif<dif){
                    a=arr[i];
                    b=arr[j];
                    dif=curdif;
                }
                else if(curdif==dif and abs(arr[i]-arr[j])>abs(a-b)){
                    a=arr[i];
                    b=arr[j];
                }
                if(sum<target)
                    ++i;
                else
                    --j;
            }
        }
        if(dif==INT_MAX)
            return {};
        return {a,b};
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
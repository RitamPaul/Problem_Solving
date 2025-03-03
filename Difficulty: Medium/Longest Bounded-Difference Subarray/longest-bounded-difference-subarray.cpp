//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> minDeque, maxDeque;
        minDeque.push_back(0);
        maxDeque.push_back(0);
        int n=arr.size();
        int localStart=0, ansStart=0, maxlen=1;
        for(int i=1; i<n; ++i) {
            // min and max uptill this index
            int mini=arr[minDeque.front()];
            if(arr[i]<mini)     mini=arr[i];
            int maxi=arr[maxDeque.front()];
            if(arr[i]>maxi)     maxi=arr[i];
            
            // difference is over
            if(maxi-mini > x) {
                // this is new MAX, so need to start window from 2nd,3rd,4th... MIN
                if(arr[i] > arr[maxDeque.front()]){
                    while(minDeque.size() && (arr[i] - arr[minDeque.front()]) > x){
                        localStart = minDeque.front() + 1;
                        minDeque.pop_front();
                    }
                }
                // this is new MIN, so need to start window from 2nd,3rd,4th... MAX
                else if(arr[i] < arr[minDeque.front()]){
                    while(maxDeque.size() && (arr[maxDeque.front()] - arr[i]) > x){
                        localStart = maxDeque.front() + 1;
                        maxDeque.pop_front();
                    }
                }
            }
            
            // within bounds
            else {
                int curlen = i - localStart + 1;
                if(curlen > maxlen) {
                    maxlen = curlen;
                    ansStart = localStart;
                }
            }
            // insert this current item
            while(minDeque.size() && arr[minDeque.back()]>arr[i])
                minDeque.pop_back();
            minDeque.push_back(i);
            while(maxDeque.size() && arr[maxDeque.back()]<arr[i])
                maxDeque.pop_back();
            maxDeque.push_back(i);
        }
        return vector<int>(arr.begin()+ansStart, arr.begin()+ansStart+maxlen);
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
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
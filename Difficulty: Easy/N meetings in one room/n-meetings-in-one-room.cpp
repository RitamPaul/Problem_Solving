//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> arr;
        
        for(int i=0; i<n; ++i)
            arr.push_back({start[i], end[i]});
        
        sort(arr.begin(), arr.end(), cmp);
        
        int prev=-1, count=0;
        
        for(int i=0; i<n; ++i){
            // initial
            if(prev == -1){
                ++count;
                prev = i;
            }
            
            int prevs = arr[prev].first;
            int preve = arr[prev].second;
            
            int curs = arr[i].first;
            int cure = arr[i].second;
            
            if(preve < curs){
                prev = i;
                ++count;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
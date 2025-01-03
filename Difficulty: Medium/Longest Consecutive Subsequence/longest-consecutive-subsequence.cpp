//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        for(auto &i : arr)
            st.insert(i);
        int ans=0;
        while(st.size()){
            int front = *st.begin();
            st.erase(front);
            int cur = front;
            int count = 1;
            // increasing up
            while(st.count(++cur)){
                ++count;
                st.erase(cur);
            }
            // decreasing down
            cur = front;
            while(st.count(--cur)){
                ++count;
                st.erase(cur);
            }
            ans = max(ans, count);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
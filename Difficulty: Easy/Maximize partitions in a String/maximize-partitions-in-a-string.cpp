//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char,int> right, left;
        for(auto &ch : s)
            ++right[ch];
        int cut=0;
        for(auto &ch : s){
            ++left[ch];
            --right[ch];
            if(right[ch]==0)
                right.erase(ch);
            bool possible=true;
            for(int i=0; i<26; ++i){
                if(left.count('a'+i) and right.count('a'+i))
                    possible=false;
            }
            if(possible)
                ++cut;
        }
        // for last char: left have all chars, right gets empty
        // so for last char ++cut will result total substring count
        return cut;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(string &s1, string &s2){
    return s1.size() < s2.size();
}
class Solution {
  public:
    int n, ans;
    int bfs(unordered_set<string> &st, string &word) {
        queue<string> q;
        q.push(word);
        int len=0;
        while(q.size()) {
            int count = q.size();
            ++len;
            while(count--) {
                string front = q.front();
                q.pop();
                for(int k=0; k<front.size(); ++k) {
                    string nextStr = front.substr(0,k) + front.substr(k+1);
                    if(st.count(nextStr))
                        q.push(nextStr);
                }
            }
        }
        return len;
    }
    int longestStringChain(vector<string>& words) {
        // Code here
        n=words.size();
        ans = 0;
        
        unordered_set<string> st;
        for(auto &s : words)
            st.insert(s);
        
        for(int i=n-1; i>=0; --i){
            int longestUptoThis = bfs(st, words[i]);
            ans = max(ans, longestUptoThis);
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
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
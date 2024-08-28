//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> freq;
        vector<pair<int,int>> temp;
        
        for(const auto &i : arr)
            ++freq[i];
        
        for(const auto &p : freq)
            temp.push_back({p.second, p.first});
        
        sort(temp.begin(), temp.end(), cmp);
        
        int k=0;
        for(const auto &p : temp){
            int freq = p.first;
            int val = p.second;
            
            while(freq--)
                arr[k++] = val;
        }
        return arr;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
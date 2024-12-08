//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ans;
    void mergesort(vector<int> &arr, int start, int end){
        if(start >= end)
            return;
        
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        
        vector<int> left = vector<int>(arr.begin()+start, arr.begin()+mid+1);
        vector<int> right = vector<int>(arr.begin()+mid+1, arr.begin()+end+1);
        
        int i=0, j=0, k=0;
        while(i<left.size() and j<right.size()){
            if(left[i] <= right[j])
                arr[start + k++] = left[i++];
            else{
                arr[start + k++] = right[j++];
                ans += (left.size() - i);
            }
        }
        while(i < left.size())
            arr[start + k++] = left[i++];
        while(j < right.size())
            arr[start + k++] = right[j++];
        return;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        ans = 0;
        int n=arr.size();
        mergesort(arr, 0, n-1);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
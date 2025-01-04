//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int ans=0;
        for(int i=0; i<n-2; i++){
            //two ptr
            int l=i+1; int h=n-1; 
            while(l<h){
                int sum = arr[i]+ arr[l] + arr[h];
                if(sum==target){
                    int t1=arr[l], c1=0, t2=arr[h], c2=0;
                    
                    while(l<=h && arr[l]==t1){
                        l++; c1++;
                    }
                
                    while(l<=h && arr[h]==t2){
                        h--; c2++;
                    }
                    
                    ans +=  (t1==t2) ? (c1*(c1-1))/2 : c1*c2 ;
                }
                else if(sum > target)
                h--;
                
                else
                    l++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
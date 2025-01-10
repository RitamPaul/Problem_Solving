//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int count=0;
        int n=arr.size();
        int left=0, right=n-1;
        while(left < right){
            int sum=arr[left]+arr[right];
            if(sum==target){
                int leftitem=arr[left], rightitem=arr[right], cl=0, cr=0;
                while(left<=right and arr[left]==leftitem){
                    ++left;
                    ++cl;
                }
                while(left<=right and arr[right]==rightitem){
                    --right;
                    ++cr;
                }
                if(leftitem==rightitem)
                    count += ((cl*(cl-1))/2);
                else
                    count += cl*cr;
            }
            else if(sum<target)
                ++left;
            else
                --right;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
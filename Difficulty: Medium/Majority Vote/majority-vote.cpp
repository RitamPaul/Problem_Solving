//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        if(n==1)
            return nums;
        int num1=nums[0], count1=1, num2=nums[1], count2=1;
        for(int i=2; i<n; ++i){
            if(num1 == nums[i])
                ++count1;
            else if(num2 == nums[i])
                ++count2;
            else if(count1==0){
                ++count1;
                num1=nums[i];
            }
            else if(count2==0){
                ++count2;
                num2=nums[i];
            }
            else{
                --count1;
                --count2;
            }
        }
        count1=count2=0;
        for(int i=0; i<n; ++i){
            if(nums[i]==num1)
                ++count1;
            else if(nums[i]==num2)
                ++count2;
        }
        vector<int> ans;
        if(count1>n/3)
            ans.push_back(num1);
        if(count2>n/3)
            ans.push_back(num2);
        if(ans.empty())
            ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
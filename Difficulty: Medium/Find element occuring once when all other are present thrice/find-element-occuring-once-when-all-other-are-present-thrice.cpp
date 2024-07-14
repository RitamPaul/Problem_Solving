//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int bit[32];
    int singleElement(int arr[] ,int N) {
        // code here
        memset(bit, 0, sizeof(bit));
        
        int mini = *min_element(arr, arr+N);
        
        // printf("(%d)", mini);
        
        if(mini < 0){
            for(int i=0; i<N; ++i)
                arr[i] += abs(mini);
        }
        
        for(int i=0; i<N; ++i){
            int num=arr[i], temp=num;
            while(temp > 0){
                temp = temp & (temp - 1);
                int dif = num - temp;
                int ind = log2(dif);
                ++bit[ind];
                num = temp;
            }
        }
        
        int ans = 0;
        for(int i=0; i<32; ++i){
            if(bit[i] % 3 > 0){
                int mask = 1 << i;
                ans = ans | mask;
            }
        }
        if(mini < 0)
            return ans - abs(mini);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
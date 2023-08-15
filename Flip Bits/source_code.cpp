class Solution{
    public:
    int maxOnes(int arr[], int n){
        // kadane's algo = reward for converting 0->1, punish for 1->0
        int sum=0, maxi=0, c1=0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0)
                sum += 1;
            else{
                sum -= 1;
                ++c1;
            }
            maxi = max(maxi, sum);
            if(sum < 0)
                sum = 0;
        }
        // cout<<"("<<maxi<<","<<c1<<")";
        return maxi + c1;
    }
};
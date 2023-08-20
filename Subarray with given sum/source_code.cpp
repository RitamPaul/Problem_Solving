class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s){
        //cout<<"["<<arr[0]<<","<<arr[1]<<"]";
        int startans=-1, endans=-1;
        long long sum=arr[0];
        int start=0, end=0;
        while(end < n){
            // target is found
            if(sum == s){
                startans = start;
                endans = end;
                break;
            }
            // current sum is greater than target
            else if(sum > s){
                sum -= arr[start];
                ++start;
            }
            
            // current sum is lesser than target
            else{
                ++end;
                sum += arr[end];
            }
        }
        if(end != n and end>=start){
            return {startans+1, endans+1};
        }
        return {-1};
    }
};
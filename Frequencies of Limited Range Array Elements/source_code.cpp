class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(auto &i : arr)
            i -= 1;
        
        for(int i=0; i<N; ++i){
            if(arr[i] % P >= N){
                arr[i] = (arr[i] / P) * P;
                continue;
            }
            arr[ arr[i] % P ] += P;
        }
        
        for(auto &i : arr)
            i /= P;
    }
};
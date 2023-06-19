class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        
        //new item stored = (array size * new actual refered item) + old item stored
        //new item actual = new item stored / array size
        //old item stored = new item stored % array size
        
        for(int i=0; i<n; i++){
            arr[i] = (n * (arr[arr[i]] % n)) + arr[i];
        }
        
        for(int i=0; i<n; i++){
            arr[i] = arr[i] / n;
        }
        
        return;
    }
};
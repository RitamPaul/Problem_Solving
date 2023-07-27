class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i){
        int left=2*i + 1, right=2*i + 2, large=i;
        if(left<n && arr[large]<arr[left])    large=left;
        if(right<n && arr[large]<arr[right])   large=right;
        if(arr[large] != arr[i]){
            swap(arr[large], arr[i]);
            heapify(arr, n, large);
        }
        return;
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n){
        for(auto i=(n/2)-1; i>=0; i--){
            heapify(arr, n, i);
        }
        return;
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        buildHeap(arr, n);
        for(auto last=n-1; last>=0; last--){
            swap(arr[0], arr[last]);
            heapify(arr, last, 0);
        }
        return;
    }
};
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int left = 0, right = m-1, dif = INT_MAX, item1, item2;
        while(left < n and right >= 0){
            if(abs(arr[left] + brr[right] - x) < dif){
                dif = abs(arr[left] + brr[right] - x);
                item1 = arr[left];
                item2 = brr[right];
            }
            if(arr[left] + brr[right] < x)
                ++left;
            else
                --right;
        }
        return {item1, item2};
    }
};
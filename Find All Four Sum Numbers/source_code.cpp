class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        int n = arr.size();
        vector<vector<int>> ans;
        if(n < 4)   return ans;
        sort(arr.begin(), arr.end());
        long long sum;
        for(int i = 0; i<n-3; ++i){
            // except for 1st case if "i" found to be duplicate
            if(i > 0 and arr[i] == arr[i-1])
                continue;
            for(int j = i+1; j<n-2; ++j){
                // except for the 1st case w.r.t "i" if "j" found to be duplicate
                if(j > i+1 and arr[j] == arr[j-1])
                    continue;
                int k = (j + 1), l = (n - 1);
                while(k < l){
                    sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == K){
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                        ++k;    --l;
                        while(k < l and arr[k] == arr[k-1]) ++k;
                        while(k < l and arr[l] == arr[l+1]) --l;
                    }
                    else if(sum < K)    ++k;
                    else                --l;
                }
            }
        }
        return ans;
    }
};
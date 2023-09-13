class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> temp(n,1);
        // for operating on increasing order but in reverse direction
        for(int i=n-1; i>0; --i){
          if(rating[i-1] > rating[i] and temp[i-1] <= temp[i])
            temp[i-1] = temp[i] + 1;
        }
        // for operating on increasing order
        for(int i=0; i<n-1; ++i){
          if(rating[i] < rating[i+1] and temp[i] >= temp[i+1])
            temp[i+1] = temp[i] + 1;
        }
        return accumulate(temp.begin(), temp.end(), 0);
    }
};
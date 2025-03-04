class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        int n=arr.size();
        for(int i=0; i<n; ++i) {
            if(temp.empty() || temp.back()<arr[i])
                temp.push_back(arr[i]);
            else{
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[index] = arr[i];
            }
        }
        return temp.size();
    }
};
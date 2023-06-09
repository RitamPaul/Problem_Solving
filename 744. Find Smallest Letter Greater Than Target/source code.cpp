class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int ind = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(ind==arr.size())
            return arr[0];
        return arr[ind];
    }
};
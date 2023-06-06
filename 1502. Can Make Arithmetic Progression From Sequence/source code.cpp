class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()==2)   return true;
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); ++i){
            if((arr[i]-arr[i-1]) != (arr[1]-arr[0]))
                return false;
        }
        return true;
    }
};
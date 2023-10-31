class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int cur, prev = 0;
        for(int &i : pref){
            cur = i;
            i = i ^ prev;
            prev = cur;
        }
        return pref;
    }
};
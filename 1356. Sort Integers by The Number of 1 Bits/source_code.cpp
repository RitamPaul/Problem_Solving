bool mycmp(int &a, int &b){
    int x = a, c1 = 0;
    while(x > 0){
        x = x & (x-1);
        ++c1;
    }
    int y = b, c2 = 0;
    while(y > 0){
        y = y & (y-1);
        ++c2;
    }
    if(c1 == c2)
        return a < b;
    return c1 < c2;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), mycmp);
        return arr;
    }
};
class Solution{
    public:
    string colName (long long int n){
        --n;
        string ans = "";
        while(n >= 0){
            int rem = n % 26;
            ans = (char)('A' + rem) + ans;
            n = (n / 26) - 1;
        }
        return ans;
    }
};
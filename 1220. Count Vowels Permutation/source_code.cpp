int ind(char ch){
    if(ch == 'a')   return 0;
    if(ch == 'e')   return 1;
    if(ch == 'i')   return 2;
    if(ch == 'o')   return 3;
    return 4;
}
vector<char> v = {'a', 'e', 'i', 'o', 'u'};
int mod = 1e9 + 7;
class Solution {
public:
    long long helper(int start, char ch, int n, vector<vector<long long>> &dp){
        // base case
        if(start == n - 1)      return 1;

        // dp found case
        if(dp[start][ind(ch)] != -1)
            return dp[start][ind(ch)];

        // recursive case
        long long count = 0;
        if(ch == 'a')
            count = (count + helper(start+1, 'e', n, dp)) % mod;
        else if(ch == 'e'){
            count = (count + helper(start+1, 'a', n, dp)) % mod;
            count = (count + helper(start+1, 'i', n, dp)) % mod;
        }
        else if(ch == 'i'){
            count = (count + helper(start+1, 'a', n, dp)) % mod;
            count = (count + helper(start+1, 'e', n, dp)) % mod;
            count = (count + helper(start+1, 'o', n, dp)) % mod;
            count = (count + helper(start+1, 'u', n, dp)) % mod;
        }
        else if(ch == 'o'){
            count = (count + helper(start+1, 'i', n, dp)) % mod;
            count = (count + helper(start+1, 'u', n, dp)) % mod;
        }
        else if(ch == 'u')
            count = (count + helper(start+1, 'a', n, dp)) % mod;

        // return from current state
        return dp[start][ind(ch)] = count;
    }
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5, -1));
        long long count = 0;
        for(char &i : v){
            count = (count + helper(0, i, n, dp)) % mod;
        }
        return count;
    }
};
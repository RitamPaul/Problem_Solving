class Solution {
public:
    unordered_map<int,int> universe;
    int helper(int n, unordered_map<int,int> &mp){
        // base case

        // dp found case
        if(universe[n] > 0)
            return universe[n];
        if(mp[n] > 0)
            return mp[n];

        // recursive case
        int leftmul, rightmul, ans = INT_MIN;
        for(int i=2; i<=n/2; ++i){
            leftmul = helper(i, mp);
            rightmul = helper(n-i, mp);
            ans = max(ans, leftmul * rightmul);
        }

        // return from current state
        return mp[n] = ans;
    }
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        unordered_map<int,int> mp;
        mp[2] = 2;      mp[3] = 3;
        return universe[n] = helper(n, mp);
    }
};
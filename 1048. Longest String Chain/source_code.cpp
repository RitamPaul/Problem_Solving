class Solution {
public:
    int helper(string str, unordered_map<string,bool> &mp, unordered_map<string,int> &dp){
      // base case

      // dp found case
      if(dp[str] != -1)
        return dp[str];

      // recursive case
      int maxi = 0;
      string  temp = "";
      for(int i=0; i<str.size(); ++i){
        temp = "";
        temp += str.substr(0, i);
        temp += str.substr(i+1, str.size()-i+1);
        if(mp[temp] == true)
          maxi = max(maxi, helper(temp, mp, dp));
      }

      // return from current state
      return dp[str] = 1 + maxi;
    }
    int longestStrChain(vector<string>& word) {
      int n = word.size();
      if(n == 1)
        return 1;
      sort(word.begin(), word.end());
      unordered_map<string,bool> mp;
      unordered_map<string,int> dp;
      for(auto str:word){
        mp[str] = true;
        dp[str] = -1;
      }
      int ans = 1;
      for(int i=n-1; i>=0; --i){
        ans = max(ans, helper(word[i], mp, dp));
      }
      return ans;
    }
};
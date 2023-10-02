//User function template for C++

class Solution{
  public:	
    int mod = 1000000007;
	int distinctSubsequences(string s){
	    int n = s.size();
	    vector<int> dp(n+1);
	    dp[0] = 1;
	    unordered_map<char,int> mp;
	    
	    for(int i=1; i<=n; ++i){
	        char ch = s[i-1];
	        dp[i] = (2 * dp[i-1]) % mod;
	        if(mp.find(ch) != mp.end()){
	            int foundatindex = mp[ch];
	            dp[i] = (dp[i] - dp[foundatindex - 1] + mod) % mod;
	        }
	        mp[ch] = i;
	    }
	    return dp[n];
	}
};
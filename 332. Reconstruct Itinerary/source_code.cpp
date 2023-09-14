class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &mp, string &cur, vector<string> &ans){
      // base case
      if(mp[cur].empty()){
        ans.push_back(cur);
        return;
      }

      // recursive case
      string top = "";
      while(mp[cur].size()){
        top = mp[cur].top();
        mp[cur].pop();
        dfs(mp, top, ans);
      }
      ans.push_back(cur);
      return;
    }
    vector<string> findItinerary(vector<vector<string>>& ticket) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
        for(auto &v:ticket)
          mp[v[0]].push(v[1]);
        string cur = "JFK";
        vector<string> ans;
        dfs(mp, cur, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
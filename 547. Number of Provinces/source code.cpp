class Solution {
public:
    int findCircleNum(vector<vector<int>>& connect) {
        int n = connect.size();
        if(n==1)    return 1;

        vector<bool> dp(n+1, false);
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(connect[i][j]==1){
                    mp[i+1].push_back(j+1);
                    mp[j+1].push_back(i+1);
                }
            }
        }

        int component = 0;

        for(int i=1; i<=n; i++){
            queue<int> q;
            q.push(i);
            if(dp[i]==false){
                dp[i]=true;
                while(q.empty()==false){
                    int count = q.size();
                    int front = q.front();
                    q.pop();
                    for(int k=1; k<=count; k++){
                        for(auto item:mp[front]){
                            if(dp[item]==false){
                                q.push(item);
                                dp[item] = true;
                            }
                        }
                    }
                }
                component++;
            }
        }

        return component;
    }
};
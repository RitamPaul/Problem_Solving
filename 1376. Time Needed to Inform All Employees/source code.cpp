class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& time) {
        if(n==1)    return time[0];

        unordered_map<int, vector<int>> mp;
        int root;
        for(int i=0; i<n; i++){
            if(manager[i] != -1)
                mp[manager[i]].push_back(i);
            else if(manager[i] == -1)
                root=i;
        }

        vector<int> leaf;
        for(auto i=0; i<n; i++){
            if(mp[i].empty()==true)
                leaf.push_back(i);
        }

        int ans=INT_MIN;
        for(auto i:leaf){
            int sum=0;
            int parent = manager[i];
            while(parent != -1){
                sum += time[parent];
                parent = manager[parent];
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};
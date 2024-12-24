class Solution {
public:
    int ans1, ans2;
    int f(int node, unordered_map<int, vector<int>> &mp, vector<bool> &vis, int &ans){
        vis[node] = true;
        // base
        if(!mp.count(node))
            return 0;
        
        int max1=0, max2=0;
        for(auto &i : mp[node]){
            if(!vis[i]){
                int res = 1 + f(i, mp, vis, ans);
                if(res >= max1){
                    max2 = max(max2, max1);
                    max1 = res;
                }
                else
                    max2 = max(max2, res);
            }
        }
        ans = max(ans, max1+max2);
        return max(max1, max2);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        if(edges1.empty() and edges2.empty())
            return 1;
        unordered_map<int, vector<int>> mp1, mp2;
        vector<bool> vis1(edges1.size()+1, false), vis2(edges2.size()+1, false);
        for(auto &v : edges1){
            mp1[v[0]].push_back(v[1]);
            mp1[v[1]].push_back(v[0]);
        }
        for(auto &v : edges2){
            mp2[v[0]].push_back(v[1]);
            mp2[v[1]].push_back(v[0]);
        }
        
        int ans1=0;
        int ans2=0;
        if(edges1.size())
            f(0, mp1, vis1, ans1);
        if(edges2.size())
            f(0, mp2, vis2, ans2);
        
        if(ans1==0){
            if(ans2==1) return 2;
            return ans2;
        }
        else if(ans2==0){
            if(ans1==1) return 2;
            return ans1;
        }
        printf("(1d=%d, 2d=%d)", ans1, ans2);

        int left1=ans1/2, right1=ans1-left1;
        int left2=ans2/2, right2=ans2-left2;

        return max({max(left1,right1)+max(left2,right2)+1, ans1, ans2});
    }
};
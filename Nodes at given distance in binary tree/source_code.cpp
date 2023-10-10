class Solution
{
private:
    void dfsfindTg(Node *nod, int k, vector<int>& ans) {
        if (!nod) return;
        if (k == 0) {
            ans.push_back(nod->data);
            return;
        } else {
            dfsfindTg(nod->left, k-1, ans);
            dfsfindTg(nod->right, k-1, ans);
        }
    }
    int findTg(Node *nod, int t, int k,
        vector<int>& ans, unordered_map<Node *, pair<bool, int>>& mp) {
        if (!nod) return -1;
        if (nod->data == t) {
            dfsfindTg(nod, k, ans);
            return 1;
        }
        int lfnd = findTg(nod->left, t, k, ans, mp);
        if (lfnd >= 1) {
            mp[nod] = { 0, lfnd };
            return 1+lfnd;
        }
        int rfnd = findTg(nod->right, t, k, ans, mp);
        if (rfnd >= 1) {
            mp[nod] = { 1, rfnd };
            return 1+rfnd;
        }
        return -1;
    }
public:
    vector<int> KDistanceNodes(Node* root, int target , int k) {
        vector<int> ans;
        unordered_map<Node*, pair<bool, int>> mp;
        findTg(root, target, k, ans, mp);
        for(auto &p : mp){
            Node *node = p.first;
            bool dir = p.second.first;
            int disfound = p.second.second;
            // cout << "(" << node->data << "," << dir << "," << disfound << ")";
            int searchdis = k - disfound;
            if(searchdis == 0){
                ans.push_back(node->data);
            }
            else if(searchdis > 0){
                // found on left side, so search in right side
                if(dir == 0)
                    dfsfindTg(node->right, searchdis-1, ans);
                // found on right side, so search in left side
                else
                    dfsfindTg(node->left, searchdis-1, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
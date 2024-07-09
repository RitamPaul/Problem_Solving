/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *root, int need, unordered_map<TreeNode *, vector<int>> &mp){
        if(!root)       return 0;
        
        if(!mp.count(root))         mp[root] = {-1, -1};
        if(mp[root][need] != -1)    return mp[root][need];

        int lc=0, rc=0, pick=0, notpick=0;
        if(need){
            // pick
            lc = dfs(root->left, 0, mp);
            rc = dfs(root->right, 0, mp);
            pick = root->val + lc + rc;
            // not pick
            lc = dfs(root->left, 1, mp);
            rc = dfs(root->right, 1, mp);
            notpick = lc + rc;
        }
        else{
            lc = dfs(root->left, 1, mp);
            rc = dfs(root->right, 1, mp);
        }

        if(need)
            return mp[root][need] = max(pick, notpick);
        return mp[root][need] = lc + rc;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, vector<int>> mp;
        return dfs(root, 1, mp);
    }
};
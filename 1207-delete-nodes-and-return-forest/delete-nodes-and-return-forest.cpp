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
    TreeNode* dfs(TreeNode *root, unordered_map<int,bool> &mp, vector<TreeNode *> &ans){
        // base case
        if(!root)       return NULL;

        // calculation
        if(mp.count(root->val)){
            if(root->left and !mp.count(root->left->val))       ans.push_back(root->left);
            if(root->right and !mp.count(root->right->val))     ans.push_back(root->right);
        }

        // recursive case
        root->left = dfs(root->left, mp, ans);
        root->right = dfs(root->right, mp, ans);
        if(mp.count(root->val))
            return NULL;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        if(!root)
            return ans;
        if(to_delete.empty())
            return {root};

        unordered_map<int,bool> mp;
        for(auto &i : to_delete)
            mp[i] = true;

        if(!mp.count(root->val))
            ans.push_back(root);

        dfs(root, mp, ans);
        return ans;
    }
};
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
    void dfs(TreeNode *root, vector<int> &ans, int level){
        if(!root)   return;

        if(ans.size() <= level)     ans.push_back(root->val);
        else        ans[level] = max(ans[level], root->val);

        dfs(root->left, ans, level+1);
        dfs(root->right, ans, level+1);

        return;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};
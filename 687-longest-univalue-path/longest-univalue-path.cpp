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
    int maxi;
    int helper(TreeNode *root, unordered_map<TreeNode *,int> &mp, TreeNode *parent){
        // base case
        if(!root)       return 0;

        // recursive case
        int lchild=0, rchild=0;
        // same value countinues
        if(parent->val == root->val){
            lchild = helper(root->left, mp, parent);
            rchild = helper(root->right, mp, parent);
            mp[root] = lchild + rchild;
        }
        // different value found
        else{
            lchild = helper(root->left, mp, root);
            rchild = helper(root->right, mp, root);
            mp[root] = lchild + rchild;
        }

        // return from current state
        if(parent->val == root->val)
            return max(lchild, rchild) + 1;
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)       return 0;
        maxi = INT_MIN;
        unordered_map<TreeNode *,int> mp;
        helper(root, mp, root);
        for(auto &p : mp)
            maxi = max(maxi, p.second);
        return maxi;
    }
};
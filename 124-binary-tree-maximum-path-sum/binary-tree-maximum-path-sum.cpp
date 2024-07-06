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

        // recursive case : inorder traversal
        int lchild=0, rchild=0, circularpath=0, leftchain=0, rightchain=0;
        lchild = helper(root->left, mp, root);
        rchild = helper(root->right, mp, root);
        circularpath = root->val + lchild + rchild;
        leftchain = root->val + lchild;
        rightchain = root->val + rchild;
        mp[root] = max(max(root->val, circularpath), max(leftchain, rightchain));

        // return from current state
        return max(root->val, max(leftchain, rightchain));
    }
    int maxPathSum(TreeNode* root) {
        if(!root)       return 0;
        maxi = INT_MIN;
        unordered_map<TreeNode *,int> mp;
        helper(root, mp, root);
        for(auto &p : mp)
            maxi = max(maxi, p.second);
        return maxi;
    }
};
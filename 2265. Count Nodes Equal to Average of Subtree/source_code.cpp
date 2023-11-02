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
    int ans;
    pair<long long,long long> helper(TreeNode *root){
        // base case
        if(!root)
            return {0,0};

        // recursive case
        pair<long long, long long> leftsubtree = helper(root->left);
        long long leftsum = leftsubtree.first;
        long long leftcount = leftsubtree.second;

        pair<long long, long long> rightsubtree = helper(root->right);
        long long rightsum = rightsubtree.first;
        long long rightcount = rightsubtree.second;

        // answer calculation
        long long totalsum = leftsum + root->val + rightsum;
        long long totalcount = leftcount + 1 + rightcount;
        if(totalsum / totalcount == root->val)
            ++ans;
        
        // return from current state
        return {totalsum, totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};
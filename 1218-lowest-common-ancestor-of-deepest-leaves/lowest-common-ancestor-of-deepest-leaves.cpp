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
    TreeNode* ans;
    int maxi;
    int helper(int parentheight, TreeNode* root){
        // base case
        if(!root)   return 0;

        // recursive case
        int leftleaf = helper(parentheight+1, root->left);
        int rightleaf = helper(parentheight+1, root->right);
        // cout << "(" << root->val << ",i=" << parentheight << ",l=" << leftleaf << ",r=" << rightleaf << ")";

        // answer calculation
        if(leftleaf == rightleaf){
            if(parentheight + leftleaf >= maxi){
                ans = root;
                maxi = parentheight + leftleaf;
            }
        }

        // return from current state
        return max(leftleaf, rightleaf) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ans = root;
        maxi = INT_MIN;
        helper(0, root);
        return ans;
    }
};
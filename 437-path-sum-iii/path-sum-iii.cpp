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
    void helper(TreeNode *root, unsigned long long sum){
        if(!root)       return;

        if(sum + root->val == target)
            ++ans;

        helper(root->left, sum+root->val);
        helper(root->right, sum+root->val);

        return;
    }
    int target, ans;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)       return 0;
        target = targetSum;
        ans = 0;
        queue<TreeNode *> q;
        TreeNode *front;
        q.push(root);
        int count;
        while(q.size()){
            count = q.size();
            while(count--){
                front = q.front();
                q.pop();
                helper(front, 0);
                if(front->left)         q.push(front->left);
                if(front->right)        q.push(front->right);
            }
        }
        return ans;
    }
};
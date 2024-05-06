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
    void helper(TreeNode *root, string &str){
        if(!root)   return;

        str += to_string(root->val);
        if(root->left or root->right){
            str += "(";
            helper(root->left, str);
            str += ")";
            
            str += "(";
            helper(root->right, str);
            if(str.back() != '(')
                str += ")";
            else
                str.pop_back();
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string str="";
        helper(root, str);
        return str;
    }
};
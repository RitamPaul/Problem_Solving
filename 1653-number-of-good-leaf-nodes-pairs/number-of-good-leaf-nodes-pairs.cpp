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
    vector<int> helper(TreeNode *root, int &dis){
        // base case
        if(!root->left and !root->right)            return {1};

        vector<int> left, right;
        if(root->left)
            left = std::move(helper(root->left, dis));
        if(root->right)
            right = std::move(helper(root->right, dis));
        
        for(int i=0; i<left.size(); ++i){
            for(int j=0; j<right.size(); ++j){
                if(left[i]+right[j] <= dis)             ++ans;
            }
        }

        vector<int> backtrack;
        for(auto &i : left){
            if(i+1 < dis)          backtrack.push_back(i+1);
        }
        for(auto &i : right){
            if(i+1 < dis)          backtrack.push_back(i+1);
        }

        return backtrack;
    }
    int countPairs(TreeNode* root, int dis) {
        ans = 0;
        helper(root, dis);
        return ans;
    }
};
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
    void dfs(TreeNode *root, int target, string &str, bool &mila){
        if(!root or mila==true)
            return;
        if(root->val == target){
            mila = true;
            return;
        }
        
        str += 'L';
        dfs(root->left, target, str, mila);
        if(mila)    return;
        else        str.pop_back();

        str += 'R';
        dfs(root->right, target, str, mila);
        if(!mila)   str.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int s, int d) {
        string start="", dest="";
        bool mila = false;
        dfs(root, s, start, mila);
        mila = false;
        dfs(root, d, dest, mila);

        if(start.empty())
            return dest;
        int i=0;
        while(i < start.size()){
            if(start[i] != dest[i])
                break;
            ++i;
        }
        string ans="";
        for(int j=i; j<start.size(); ++j)
            ans += 'U';
        for(int j=i; j<dest.size(); ++j)
            ans += dest[j];
        return ans;
    }
};
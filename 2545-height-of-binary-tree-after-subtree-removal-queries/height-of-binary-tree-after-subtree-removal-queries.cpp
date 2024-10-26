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
    int helper(TreeNode *root, unordered_map<int,int> &level, int l, unordered_map<int,int> &height, int h){
        // base case
        if(!root)   return 0;
        level[root->val] = l;
        int maxchildheight = max(helper(root->left, level, l+1, height, h+1), helper(root->right, level, l+1, height, h+1));
        height[root->val] = h + maxchildheight;
        return maxchildheight + 1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& query) {
        // level = which node->val is in which level
        // height = height of tree considering branch of this node only
        unordered_map<int,int> level, height;
        // putting value of level and height
        helper(root, level, 0, height, 0);
        // sibling = heap of nodes in a particular level stored acc.
        // to their contribution of height
        vector<priority_queue<pair<int,int>>> sibling;
        // bfs for putting siblings of same level acc. to their height contribution
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()){
            int count = q.size();
            sibling.push_back(priority_queue<pair<int,int>>());
            while(count--){
                TreeNode *front = q.front();
                sibling.back().push({height[front->val], front->val});
                q.pop();
                if(front->left)         q.push(front->left);
                if(front->right)        q.push(front->right);
            }
        }
        for(int i=0; i<query.size(); ++i){
            int nodeval = query[i];
            int lev = level[nodeval];
            // node is not contributing maximum height of tree
            if(sibling[lev].top().second != nodeval)
                query[i] = sibling[lev].top().first;
            // maximum height of the tree is for this node
            else{
                // have sibling in same level
                if(sibling[lev].size() > 1){
                    pair<int,int> top = sibling[lev].top();
                    sibling[lev].pop();
                    query[i] = sibling[lev].top().first;
                    sibling[lev].push(top);
                }
                // don't have sibling
                else
                    query[i] = lev - 1;
            }
        }
        return query;
    }
};
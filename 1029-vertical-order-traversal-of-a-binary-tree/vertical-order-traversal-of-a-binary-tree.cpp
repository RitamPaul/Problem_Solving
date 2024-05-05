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
    int mini, maxi;
    void put(TreeNode *root, int row, int col,
            map<pair<int,int>,vector<int>> &mp){
        if(!root)       return;

        mini = min(mini, col);
        maxi = max(maxi, col);
        mp[{row,col}].push_back(root->val);
        put(root->left, row+1, col-1, mp);
        put(root->right, row+1, col+1, mp);
        return;
    }
    void helper(TreeNode *root, map<pair<int,int>,vector<int>> &mp,
                vector<vector<int>> &ans){
        unordered_map<TreeNode *,pair<int,int>> ind;
        queue<TreeNode *> q;
        q.push(root);
        ind[root] = {0,0};
        int count, row, col;
        TreeNode *front;
        while(q.size()){
            count = q.size();
            while(count--){
                front = q.front();
                q.pop();
                row = ind[front].first;
                col = ind[front].second;

                sort(mp[{row,col}].begin(), mp[{row,col}].end(), greater<int>());
                while(mp[{row,col}].size()){
                    ans[col+abs(mini)].push_back( mp[{row,col}].back() );
                    mp[{row,col}].pop_back();
                }

                if(front->left){
                    q.push(front->left);
                    ind[front->left] = {row+1, col-1};
                }
                if(front->right){
                    q.push(front->right);
                    ind[front->right] = {row+1, col+1};
                }
            }
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mini = maxi = 0;
        map<pair<int,int>,vector<int>> mp;
        put(root, 0, 0, mp);
        vector<vector<int>> ans(maxi - mini + 1);
        helper(root, mp, ans);
        return ans;
    }
};
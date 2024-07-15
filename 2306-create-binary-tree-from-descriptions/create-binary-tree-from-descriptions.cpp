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
    TreeNode *build(int data, unordered_map<int, pair<int,int>> &child){
        if(data == 0)
            return NULL;

        TreeNode *node = new TreeNode(data);
        node->left = build(child[data].first, child);
        node->right = build(child[data].second, child);
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, pair<int,int>> child;
        unordered_map<int,bool> parent;
        for(auto &v : desc){
            parent[v[1]] = v[0];
            if(v[2] == 1)
                child[v[0]].first = v[1];
            else
                child[v[0]].second = v[1];
        }
        int head;
        for(auto &v : desc){
            if(parent.find(v[0]) == parent.end()){
                head = v[0];
                break;
            }
        }
        return build(head, child);
    }
};
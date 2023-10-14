class Solution
{
    public:
    void fill(Node *root, unordered_map<int,int> &mp){
        if(!root)   return;
        fill(root->left, mp);
        ++mp[root->data];
        fill(root->right, mp);
    }
    void helper(Node *root, unordered_map<int,int> &mp, vector<int> &ans){
        if(!root)   return;
        helper(root->left, mp, ans);
        if(mp[root->data] > 0){
            ans.push_back(root->data);
            --mp[root->data];
        }
        helper(root->right, mp, ans);
    }
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {   unordered_map<int,int> mp;
        fill(root1, mp);
        vector<int> ans;
        helper(root2, mp, ans);
        return ans;
    }
};
class Solution
{
    public:
    void dfs(Node *root, Node *&pre, Node *&suc, int key){
        if(root==NULL)
            return;
        
        dfs(root->left, pre, suc, key);
        
        if(root->key < key)
            pre = root;
        if(suc==NULL && root->key > key){
            suc = root;
            return;
        }
        
        dfs(root->right, pre, suc, key);
        return;
    }
    
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre=NULL, suc=NULL;
        dfs(root, pre, suc, key);
        return;
    }
};
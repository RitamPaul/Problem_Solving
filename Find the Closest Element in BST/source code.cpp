class Solution
{
    public:
    void func(Node *root, int k, int &ans){
        if(root==NULL)
            return;
        
        //left traversal
        func(root->left, k, ans);
        
        //calculations
        int dif = abs(root->data - k);
        ans = min(ans, dif);
        
        //right traversal
        func(root->right, k, ans);
    }
    
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int k){
        int ans=INT_MAX;
        func(root, k, ans);
        return ans;
    }
};
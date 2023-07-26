//User function Template for C++

/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/

void dfs(Node *root, int k, int node, int &help, int &ans){
    //base case
    if(!root)       return;
    
    //calculations of pre-order traversal
    if(root->data == node){
        help--;
        return;
    }
    
    //recursive calls
    dfs(root->left, k, node, help, ans);
    
    if(help < k){
        help--;
        if(help == -1)
            ans = root->data;
        return;
    }
    
    dfs(root->right, k, node, help, ans);
    
    if(help < k){
        help--;
        if(help == -1)
            ans = root->data;
    }
    return;
}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node){
    int ans=-1;
    dfs(root, k, node, k, ans);
    return ans;
}
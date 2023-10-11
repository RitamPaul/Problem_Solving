/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    int helper(Node *root){
        if(!root)
            return 1e7;
            
        int leftheight = helper(root->left);
        if(leftheight == false)
            return false;
        int rightheight = helper(root->right);
        if(rightheight == false)
            return false;
            
        int balancefactor = leftheight - rightheight;
        
        if(-1 <= balancefactor and balancefactor <= 1)
            return 1 + max(leftheight, rightheight);
        return false;
        
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root){
        return helper(root);
    }
};
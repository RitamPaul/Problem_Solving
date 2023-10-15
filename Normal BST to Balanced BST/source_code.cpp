/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution{
    
    public:
    void fill(Node *root, vector<Node *> &arr){
        if(!root)   return;
        fill(root->left, arr);
        arr.push_back(root);
        fill(root->right, arr);
    }
    Node *build(int start, int end, vector<Node *> &arr){
        if(start > end)     return NULL;
        int mid = start + (end - start) / 2;
        arr[mid]->left = build(start, mid-1, arr);
        arr[mid]->right = build(mid+1, end, arr);
        return arr[mid];
    }
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root){
        vector<Node *> inorder;
        fill(root, inorder);
        return build(0, inorder.size()-1, inorder);
    }
};
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    void insert(Node *root, vector<int> &node){
        if(!root)
            return;
        insert(root->left, node);
        node.push_back(root->data);
        insert(root->right, node);
        return;
    }
    void make(Node *root, vector<int> &node, int &ind){
        if(!root)
            return;
        make(root->left, node, ind);
        root->data = node[ind++];
        make(root->right, node, ind);
        return;
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root){
        if(!root->left and !root->right)
            return root;
        vector<int> node;
        insert(root, node);
        sort(node.begin(), node.end());
        int ind = 0;
        make(root, node, ind);
        return root;
    }
};
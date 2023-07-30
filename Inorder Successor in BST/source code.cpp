/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x){
        if(!x)      return NULL;
        Node *great=NULL, *ptr=root;
        bool find=false;
        while(true){
            if(!ptr)    return great;
            if(ptr->data > x->data)     great = ptr;
            
            if(find==true){
                ptr=ptr->left;
                continue;
            }
            
            if(ptr->data == x->data){
                find = true;
                ptr = ptr->right;
            }
            else if(x->data < ptr->data)
                ptr = ptr->left;
            else if(x->data > ptr->data)
                ptr = ptr->right;
        }
    }
};
// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
        Node* insert(Node* node, int data){
            if(!node){
                Node *root = new Node(data);
                return root;
            }
            else if(data < node->data)
                node->left = insert(node->left, data);
            else if(data > node->data)
                node->right = insert(node->right, data);
            // I don't care for the remaining case like:-
            // data == node->data
            return node;
        }
};
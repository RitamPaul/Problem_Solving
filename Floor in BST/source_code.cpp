// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        while(root){
            if(x == root->data)
                return root->data;
            else if(x < root->data)
                root = root->left;
            else{
                ans = root->data;
                root = root->right;
            }
        }
        return ans;
    }
};
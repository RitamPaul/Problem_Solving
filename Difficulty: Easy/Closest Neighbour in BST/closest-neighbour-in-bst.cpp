/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int ans;
    void f(Node *root, int k){
        if(!root)
            return;
        
        if(root->data <= k)
            this->ans = max(this->ans,root->data);
            
        if(root->data < k)
            f(root->right,k);
        else if(root->data > k)
            f(root->left,k);
        
        return;
    }
    int findMaxFork(Node* root, int k) {
        // code here
        this->ans=-1;
        f(root, k);
        return this->ans;
    }
};
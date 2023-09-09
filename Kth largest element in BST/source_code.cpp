/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int &K){
        if(!root)       return INT_MAX;
        int ansright = kthLargest(root->right, K);
        if(ansright != INT_MAX)
            return ansright;
        
        --K;
        if(K==0)        return root->data;
        
        int ansleft = kthLargest(root->left, K);
        return ansleft;
    }
};
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int k)
    {
        Node *ptr=root;
        int ud=INT_MAX, ld=INT_MAX;
        while(ptr){
            if(ptr->data < k){
                ld = min(ld, abs(ptr->data - k));
                ptr = ptr->right;
            }
            else if(ptr->data > k){
                ud = min(ud, abs(ptr->data - k));
                ptr = ptr->left;
            }
            else if(ptr->data == k)
                return 0;
        }
        return min(ld, ud);
    }
};
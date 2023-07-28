//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2){
            //prev = the root containing the same ancestor
            //p1 = the root searching for n1
            //p2 = the root searching for n2
            Node *prev=root, *p1=root, *p2=root;
            
            //loop execution till both p1!=NULL and p2!=NULL
            while(p1 && p2){
                
                //if both p1, p2 value same, storing it as common ancestor
                if(p1->data == p2->data)    prev = p1;
                
                if(p1->data==n1 && p2->data==n2)    break;
                
                //if p1 value = n1, don't change p1 node for next iteration
                //else p1 node will change according to condition
                if(n1 > p1->data)       p1=p1->right;
                else if(n1 < p1->data)  p1=p1->left;
                
                //if p2 value = n2, don't change p2 node for next iteration
                //else p2 node will change according to condition
                if(n2 > p2->data)       p2=p2->right;
                else if(n2 < p2->data)  p2=p2->left;
            }
            
            //if anyone node pointer become NULL without finding n1 and n2
            return prev;
        }
};
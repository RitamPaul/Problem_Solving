class Solution
{
    public:   
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre=NULL, suc=NULL;
        Node *ptr=root;
        
        while(ptr){
            if(ptr->key < key){
                pre = ptr;
                ptr = ptr->right;
            }
            else if(ptr->key > key){
                suc = ptr;
                ptr = ptr->left;
            }
            else if(ptr->key == key){
                Node * p = ptr->left;
                Node * q = ptr->right;
                while(p){
                    pre = p;
                    p = p->right;
                }
                
                while(q!=NULL && q->key > key){
                    suc = q;
                    q = q->left;
                }
                
                return;
            }
        }
        
        return;
    }
};
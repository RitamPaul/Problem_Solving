/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    if(x==1)
        return head->next;
    int ind=1;
    Node *ptr=head, *prev=NULL;
    while(ptr){
        if(ind==x and prev){
            prev->next = ptr->next;
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
        ++ind;
    }
    return head;
}
Node *removeDuplicates(Node *head)
{   Node *ptr=head, *prev=head;
    while(ptr){
        if(ptr->data == prev->data){
            while(ptr and ptr->data == prev->data)
                ptr = ptr->next;
            prev->next = ptr;
            prev = ptr;
        }
    }
    return head;
}
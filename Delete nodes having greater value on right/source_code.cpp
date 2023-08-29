class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node *ptr=head, *before=NULL, *after=NULL;
        // reverse the linked list
        while(ptr){
            after = ptr;
            ptr = ptr->next;
            after->next = before;
            before = after;
        }
        ptr = after;
        // building own linked list for answer
        int maxi = INT_MIN;
        Node *right=NULL;
        while(ptr){
            maxi = max(maxi, ptr->data);
            if(maxi <= ptr->data){
                Node *left = new Node(maxi);
                if(right)
                    left->next = right;
                right = left;
            }
            ptr = ptr->next;
        }
        return right;
    }
};
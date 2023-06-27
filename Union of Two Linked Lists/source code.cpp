/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> s;
        Node *ptr = head1;
        while(ptr){
            s.insert(ptr->data);
            ptr = ptr->next;
        }
        ptr = head2;
        while(ptr){
            s.insert(ptr->data);
            ptr = ptr->next;
        }
        Node *anshead=NULL, *prev=NULL, *current;
        for(auto item:s){
            current = new Node(item);
            if(!anshead)
                anshead = current;
            if(prev)
                prev->next = current;
            prev = current;
        }
        return anshead;
    }
};
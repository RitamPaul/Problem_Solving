/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *node  = new Node(data);
        if(data <= head->data){
            node->next = head;
            return node;
        }
        Node *ptr = head, *prev = NULL;
        while(ptr){
            if(prev and prev->data <= data and data <= ptr->data){
                prev->next = node;
                node->next = ptr;
                break;
            }
            else if(!ptr->next and ptr->data < data){
                ptr->next = node;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
public:
    Node* pairWiseSwap(struct Node* head)
    {
        if (!head) return head;
        if (!head->next) return head;
        Node *ptr = head;
        Node *ret = ptr->next;
        while (ptr && ptr->next) {
            Node *tmp1 = ptr;
            Node *tmp2 = ptr->next;

            ptr = ptr->next->next;

            tmp2->next = tmp1;
            tmp1->next = (ptr && ptr->next) ? ptr->next : ptr;
        }
        return ret;
    }
};
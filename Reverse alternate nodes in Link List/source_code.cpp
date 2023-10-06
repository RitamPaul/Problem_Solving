/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
public:
    void rearrange(Node *list)
    {
        bool flag = false; // EVEN posn
        Node *ptr = list;
        Node *oddhead = NULL, *odd = NULL;
        Node *evenhead = NULL, *even = NULL;
        Node *temp = NULL;
        while (ptr) {
            temp = ptr->next;
            if (!flag) {
                if (!even) 
                    evenhead = even = ptr;
                else {
                    even->next = ptr;
                    even = even->next;
                    even->next = NULL;
                }
            } 
            else {
                ptr->next = odd;
                odd = ptr;
            }
            ptr = temp;
            flag = !flag;
        }
        oddhead = odd;
        even->next = oddhead;
        list = evenhead;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *head=NULL, *ptr=NULL, *p1=head1, *p2=head2;
        while(p1 and p2){
            if(p1->data<=p2->data){
                if(!head)
                    head=ptr=p1;
                else{
                    ptr->next=p1;
                    ptr=ptr->next;
                }
                p1=p1->next;
            }
            else{
                if(!head)
                    head=ptr=p2;
                else{
                    ptr->next=p2;
                    ptr=ptr->next;
                }
                p2=p2->next;
            }
        }
        while(p1){
            if(!head)
                head=ptr=p1;
            else{
                ptr->next=p1;
                ptr=ptr->next;
            }
            p1=p1->next;
        }
        while(p2){
            if(!head)
                head=ptr=p2;
            else{
                ptr->next=p2;
                ptr=ptr->next;
            }
            p2=p2->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends